#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/ioctl.h>
#include <linux/uaccess.h>
#include "demo_ioctl.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Demo");
MODULE_DESCRIPTION("IOCTL decode example");

static dev_t devnum;
static struct cdev cdev_obj;
static struct class *cls;

/* -------- IOCTL HANDLER -------- */
static long demo_ioctl(struct file *file,
                       unsigned int cmd,
                       unsigned long arg)
{
    pr_info("IOCTL cmd = 0x%x\n", cmd);
    pr_info("Type (magic) : %c\n", _IOC_TYPE(cmd));
    pr_info("Number       : %d\n", _IOC_NR(cmd));
    pr_info("Direction    : %d\n", _IOC_DIR(cmd));
    pr_info("Size         : %d bytes\n", _IOC_SIZE(cmd));

    if (_IOC_DIR(cmd) & _IOC_READ)
        pr_info("Direction: READ (kernel -> user)\n");

    if (_IOC_DIR(cmd) & _IOC_WRITE)
        pr_info("Direction: WRITE (user -> kernel)\n");

    return 0;
}

/* -------- File operations -------- */
static struct file_operations fops = {
    .owner          = THIS_MODULE,
    .unlocked_ioctl = demo_ioctl,
};


/* -------- INIT -------- */
static int __init demo_init(void)
{
    alloc_chrdev_region(&devnum, 0, 1, "demo_ioctl");

    cdev_init(&cdev_obj, &fops);
    cdev_add(&cdev_obj, devnum, 1);

    cls = class_create("demo_ioctl_class");
   
    device_create(cls, NULL, devnum, NULL, "ioctl_info");

    pr_info("demo_ioctl driver loaded (Major=%d)\n", MAJOR(devnum));
    return 0;
}

/* -------- EXIT -------- */
static void __exit demo_exit(void)
{
    device_destroy(cls, devnum);
    class_destroy(cls);
    cdev_del(&cdev_obj);
    unregister_chrdev_region(devnum, 1);

    pr_info("demo_ioctl driver unloaded\n");
}

module_init(demo_init);
module_exit(demo_exit);


