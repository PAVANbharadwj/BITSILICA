#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/atomic.h>

#define DEVICE_NAME "singleopen"
#define CLASS_NAME  "single_class"

static dev_t dev_num;
static struct cdev so_cdev;
static struct class *so_class;


static atomic_t device_available = ATOMIC_INIT(1);


static int so_open(struct inode *inode, struct file *file)
{

    if (!atomic_dec_and_test(&device_available)) {
        atomic_inc(&device_available); 
        pr_err("singleopen: device busy\n");
        return -EBUSY;
    }

    pr_info("singleopen: device opened successfully\n");
    return 0;
}


static int so_release(struct inode *inode, struct file *file)
{
    atomic_inc(&device_available);
    pr_info("singleopen: device released\n");
    return 0;
}

static struct file_operations so_fops = {
    .owner   = THIS_MODULE,
    .open    = so_open,
    .release = so_release,
};

static int __init so_init(void)
{
    alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);

    cdev_init(&so_cdev, &so_fops);
    cdev_add(&so_cdev, dev_num, 1);

    so_class = class_create(CLASS_NAME);
    device_create(so_class, NULL, dev_num, NULL, DEVICE_NAME);

    pr_info("singleopen: driver loaded\n");
    return 0;
}

static void __exit so_exit(void)
{
    device_destroy(so_class, dev_num);
    class_destroy(so_class);
    cdev_del(&so_cdev);
    unregister_chrdev_region(dev_num, 1);

    pr_info("singleopen: driver unloaded\n");
}

module_init(so_init);
module_exit(so_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Example");
MODULE_DESCRIPTION("Single open only character driver");

