#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include "mystruct.h"

MODULE_LICENSE("GPL");

static dev_t devnum;
static struct cdev cdev_obj;
static struct class *class;
static struct mydata kernel_struct;

/* ------------ WRITE: User → Kernel --------------- */
static ssize_t simple_write(struct file *file, const char __user *buf,
                            size_t len, loff_t *off)
{
    if (len < sizeof(struct mydata))
        return -EINVAL;

    if (copy_from_user(&kernel_struct, buf, sizeof(kernel_struct)))
        return -EFAULT;

    pr_info("Kernel received struct:\n");
    pr_info("id = %d\n", kernel_struct.id);
    pr_info("value = %d\n", kernel_struct.value);
    pr_info("name = %s\n", kernel_struct.name);

    return sizeof(struct mydata);
}

/* ------------ READ: Kernel → User --------------- */
static ssize_t simple_read(struct file *file, char __user *buf,
                           size_t len, loff_t *off)
{
    if (*off != 0)
        return 0; // send once

    if (copy_to_user(buf, &kernel_struct, sizeof(kernel_struct)))
        return -EFAULT;

    *off = sizeof(kernel_struct);
    return sizeof(kernel_struct);
}

/* ------------ File Operations --------------- */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read  = simple_read,
    .write = simple_write,
};


/* ------------ INIT --------------- */
static int __init simple_init(void)
{
    /* allocate major/minor */
    alloc_chrdev_region(&devnum, 0, 1, "structdev");

    /* register cdev */
    cdev_init(&cdev_obj, &fops);
    cdev_add(&cdev_obj, devnum, 1);

    /* create class */
    class = class_create("structdev_class");

    /* create device in /dev */
    device_create(class, NULL, devnum, NULL, "structdev");

    pr_info("Driver loaded. Major=%d\n", MAJOR(devnum));
    return 0;
}

/* ------------ EXIT --------------- */
static void __exit simple_exit(void)
{
    device_destroy(class, devnum);
    class_destroy(class);

    cdev_del(&cdev_obj);
    unregister_chrdev_region(devnum, 1);

    pr_info("Driver unloaded\n");
}

module_init(simple_init);
module_exit(simple_exit);

