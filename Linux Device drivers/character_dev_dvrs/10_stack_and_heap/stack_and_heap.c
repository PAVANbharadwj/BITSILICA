#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#include "mystruct.h"

#define DEVICE_NAME "mystruct"
#define CLASS_NAME  "mystruct_class"

static dev_t dev;
static struct cdev my_cdev;
static struct class *my_class;

/* ---------------- WRITE ---------------- */
static ssize_t my_write(struct file *file,
                        const char __user *buf,
                        size_t len,
                        loff_t *off)
{
    struct abc kdata;
    char *kstr;

    /* Step 1: copy structure */
    if (copy_from_user(&kdata, buf, sizeof(kdata)))
        return -EFAULT;

    printk(KERN_INFO "Received i = %d\n", kdata.i);

    /* Step 2: copy pointed heap memory */
    kstr = kmalloc(100, GFP_KERNEL);
    if (!kstr)
        return -ENOMEM;

    if (copy_from_user(kstr, kdata.str, 100)) {
        kfree(kstr);
        return -EFAULT;
    }

    printk(KERN_INFO "Received str = %s\n", kstr);

    kfree(kstr);
    return sizeof(kdata);
}

/* ---------------- FILE OPS ---------------- */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .write = my_write,
};

/* ---------------- INIT ---------------- */
static int __init my_init(void)
{
    alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME);

    cdev_init(&my_cdev, &fops);
    cdev_add(&my_cdev, dev, 1);

    my_class = class_create(CLASS_NAME);
    device_create(my_class, NULL, dev, NULL, DEVICE_NAME);

    printk(KERN_INFO "mystruct driver loaded\n");
    return 0;
}

/* ---------------- EXIT ---------------- */
static void __exit my_exit(void)
{
    device_destroy(my_class, dev);
    class_destroy(my_class);

    cdev_del(&my_cdev);
    unregister_chrdev_region(dev, 1);

    printk(KERN_INFO "mystruct driver unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("You");
MODULE_DESCRIPTION("User struct with heap pointer example");

