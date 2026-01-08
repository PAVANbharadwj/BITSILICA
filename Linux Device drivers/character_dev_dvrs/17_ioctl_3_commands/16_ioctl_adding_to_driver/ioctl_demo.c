#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include "simple_ioctl.h"

MODULE_LICENSE("GPL");

static dev_t devnum;
static struct cdev cdev_obj;
static struct class *cls;

static int kernel_value = 0;

/* ---------------- IOCTL ---------------- */
static long simple_ioctl(struct file *file,
                         unsigned int cmd,
                         unsigned long arg)
{
    switch (cmd) {

    case IOCTL_SET_VALUE:
        if (copy_from_user(&kernel_value,
                           (int __user *)arg,
                           sizeof(int)))
            return -EFAULT;

        pr_info("Kernel: value set to %d\n", kernel_value);
        break;

    case IOCTL_GET_VALUE:
        if (copy_to_user((int __user *)arg,
                         &kernel_value,
                         sizeof(int)))
            return -EFAULT;

        pr_info("Kernel: value sent to user\n");
        break;

    default:
        return -EINVAL;
    }

    return 0;
}

/* ---------------- File ops ---------------- */
static struct file_operations fops = {
    .owner          = THIS_MODULE,
    .unlocked_ioctl = simple_ioctl,
};


/* ---------------- INIT ---------------- */
static int __init simple_init(void)
{
    alloc_chrdev_region(&devnum, 0, 1, "simple_ioctl");

    cdev_init(&cdev_obj, &fops);
    cdev_add(&cdev_obj, devnum, 1);

    cls = class_create("simple_ioctl_class");

    device_create(cls, NULL, devnum, NULL, "simple_ioctl");

    pr_info("simple_ioctl driver loaded\n");
    return 0;
}

/* ---------------- EXIT ---------------- */
static void __exit simple_exit(void)
{
    device_destroy(cls, devnum);
    class_destroy(cls);
    cdev_del(&cdev_obj);
    unregister_chrdev_region(devnum, 1);

    pr_info("simple_ioctl driver unloaded\n");
}

module_init(simple_init);
module_exit(simple_exit);

