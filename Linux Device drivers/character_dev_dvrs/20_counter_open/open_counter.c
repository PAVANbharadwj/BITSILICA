#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/atomic.h>

#define DEVICE_NAME "opencounter"
#define CLASS_NAME  "oc_class"

static dev_t dev_num;
static struct cdev oc_cdev;
static struct class *oc_class;

/* Open counter */
static atomic_t open_count = ATOMIC_INIT(0);

/* open() */
static int oc_open(struct inode *inode, struct file *file)
{
    int count = atomic_inc_return(&open_count);

    pr_info("opencounter: device opened %d times\n", count);
    return 0;
}

/* release() */
static int oc_release(struct inode *inode, struct file *file)
{
    pr_info("opencounter: device closed\n");
    return 0;
}

/* read() – return open count to user */
static ssize_t oc_read(struct file *file, char __user *buf,
                       size_t len, loff_t *offset)
{
    char msg[50];
    int msg_len;

    if (*offset > 0)
        return 0;

    msg_len = snprintf(msg, sizeof(msg),
                       "Open count: %d\n",
                       atomic_read(&open_count));

    if (copy_to_user(buf, msg, msg_len))
        return -EFAULT;

    *offset = msg_len;
    return msg_len;
}

static struct file_operations oc_fops = {
    .owner   = THIS_MODULE,
    .open    = oc_open,
    .release = oc_release,
    .read    = oc_read,
};

static int __init oc_init(void)
{
    alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);

    cdev_init(&oc_cdev, &oc_fops);
    cdev_add(&oc_cdev, dev_num, 1);

    oc_class = class_create(CLASS_NAME);
    device_create(oc_class, NULL, dev_num, NULL, DEVICE_NAME);

    pr_info("opencounter: driver loaded\n");
    return 0;
}

static void __exit oc_exit(void)
{
    device_destroy(oc_class, dev_num);
    class_destroy(oc_class);
    cdev_del(&oc_cdev);
    unregister_chrdev_region(dev_num, 1);

    pr_info("opencounter: driver unloaded\n");
}

module_init(oc_init);
module_exit(oc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Example");
MODULE_DESCRIPTION("Character driver with open counter");

