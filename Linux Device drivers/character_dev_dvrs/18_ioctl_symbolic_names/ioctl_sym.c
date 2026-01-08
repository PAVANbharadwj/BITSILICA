#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include "three_ioctl.h"

MODULE_LICENSE("GPL");

static dev_t devnum;
static struct cdev cdev_obj;
static struct class *cls;

static int kernel_value = 0;

/* ---------------- IOCTL HANDLER ---------------- */
static long my_ioctl(struct file *file,
                     unsigned int cmd,
                     unsigned long arg)
{
    switch (cmd) {

    case IOCTL_SET_VAL:
        if (copy_from_user(&kernel_value,
                           (int __user *)arg,
                           sizeof(int)))
            return -EFAULT;

        pr_info("IOCTL: SET value = %d\n", kernel_value);
        break;

    case IOCTL_GET_VAL:
        if (copy_to_user((int __user *)arg,
                         &kernel_value,
                         sizeof(int)))
            return -EFAULT;

        pr_info("IOCTL: GET value = %d\n", kernel_value);
        break;

    case IOCTL_CLEAR_VAL:
        kernel_value = 0;
        pr_info("IOCTL: CLEAR value\n");
        break;

    default:
        return -EINVAL;
    }

    return 0;
}

static struct file_operations fops = {
    .owner          = THIS_MODULE,
    .unlocked_ioctl = my_ioctl,
};



static int __init my_init(void)
{
    alloc_chrdev_region(&devnum, 0, 1, "three_ioctl");

    cdev_init(&cdev_obj, &fops);
    cdev_add(&cdev_obj, devnum, 1);
    cls = class_create("three_ioctl_class");

    device_create(cls, NULL, devnum, NULL, "three_ioctl");

    pr_info("three_ioctl driver loaded\n");
    return 0;
}

static void __exit my_exit(void)
{
    device_destroy(cls, devnum);
    class_destroy(cls);
    cdev_del(&cdev_obj);
    unregister_chrdev_region(devnum, 1);

    pr_info("three_ioctl driver unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

