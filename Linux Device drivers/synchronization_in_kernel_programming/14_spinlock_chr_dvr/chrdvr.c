#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/spinlock.h>
#include <linux/smp.h>

MODULE_LICENSE("GPL");

#define DEVICE_NAME "spinonly"

static dev_t devno;
static struct cdev mycdev;
static struct class *cls;
static struct device *dev;

/* shared data to demonstrate protection */
static int shared_counter = 0;

/* spinlock for full device locking */
static DEFINE_SPINLOCK(dev_lock);

static int spin_only_open(struct inode *inode, struct file *file)
{
    pr_info("%s: Trying to acquire spinlock on CPU %d\n",
            __func__, smp_processor_id());

    /* lock whole device */
    spin_lock(&dev_lock);

    shared_counter++;   /* modify protected data */

    pr_info("%s: Spinlock acquired on CPU %d, shared_counter=%d\n",
            __func__, smp_processor_id(), shared_counter);

    return 0;
}

static int spin_only_release(struct inode *inode, struct file *file)
{
    shared_counter--;   /* modify protected data */

    pr_info("%s: Releasing spinlock on CPU %d, shared_counter=%d\n",
            __func__, smp_processor_id(), shared_counter);

    /* unlock whole device */
    spin_unlock(&dev_lock);

    pr_info("%s: Spinlock released on CPU %d\n",
            __func__, smp_processor_id());
    return 0;
}

/* nothing in read/write, just placeholders */
static ssize_t spin_only_read(struct file *file,
    char __user *buf, size_t count, loff_t *ppos)
{
    pr_info("%s: read() (no data)\n", __func__);
    return 0;
}

static ssize_t spin_only_write(struct file *file,
    const char __user *buf, size_t count, loff_t *ppos)
{
    pr_info("%s: write() ignored (spinlock demo)\n", __func__);
    return count;
}

static const struct file_operations fops = {
    .owner   = THIS_MODULE,
    .open    = spin_only_open,
    .release = spin_only_release,
    .read    = spin_only_read,
    .write   = spin_only_write,
};

/* init/exit */
static int __init spin_only_init(void)
{
    alloc_chrdev_region(&devno, 0, 1, DEVICE_NAME);
    cdev_init(&mycdev, &fops);
    cdev_add(&mycdev, devno, 1);

    cls = class_create(DEVICE_NAME);
    dev = device_create(cls, NULL, devno, NULL, DEVICE_NAME);

    pr_info("spin-only driver loaded at /dev/%s\n", DEVICE_NAME);
    return 0;
}

static void __exit spin_only_exit(void)
{
    device_destroy(cls, devno);
    class_destroy(cls);
    cdev_del(&mycdev);
    unregister_chrdev_region(devno, 1);

    pr_info("spin-only driver unloaded\n");
}

module_init(spin_only_init);
module_exit(spin_only_exit);

