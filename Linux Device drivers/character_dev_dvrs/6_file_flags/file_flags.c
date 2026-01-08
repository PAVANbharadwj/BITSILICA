#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "simplechar"
#define BUF_SIZE 1024

MODULE_LICENSE("GPL");

static dev_t devnum;         
static struct cdev cdev_obj;
static struct class *class;      
static char buffer[BUF_SIZE] = "Hello from kernel!\n";


static int dev_open(struct inode *inode, struct file *file)
{
    pr_info("simplechar: %s called\n", __func__);

    if (file->f_flags & O_CREAT)
        pr_info("simplechar: O_CREAT → create if not exists\n");

    if (file->f_flags & O_EXCL)
        pr_info("simplechar: O_EXCL → exclusive create\n");

    if (file->f_flags & O_TRUNC)
        pr_info("simplechar: O_TRUNC → truncate file\n");

    if (file->f_flags & O_APPEND)
        pr_info("simplechar: O_APPEND → append mode\n");

    if (file->f_flags & O_NONBLOCK)
        pr_info("simplechar: O_NONBLOCK → non-blocking mode\n");

    if (file->f_flags & O_SYNC)
        pr_info("simplechar: O_SYNC → writes are synchronous\n");

    if (file->f_flags & O_DSYNC)
        pr_info("simplechar: O_DSYNC → data sync only\n");

    pr_info("simplechar: device opened successfully\n");
    return 0;
}


static int dev_release(struct inode *inode, struct file *file)
{
    pr_info("simplechar: device closed\n");
    return 0;
}

static ssize_t simple_read(struct file *file, char __user *buf,
                           size_t len, loff_t *offset)
{
    size_t remaining = strlen(buffer) - *offset;

    if (remaining == 0)
        return 0;

    if (len > remaining)
        len = remaining;

    if (copy_to_user(buf, buffer + *offset, len))
        return -EFAULT;

    *offset += len;
    return len;
}

static ssize_t simple_write(struct file *file, const char __user *buf,
                            size_t len, loff_t *offset)
{
    if (len > BUF_SIZE - 1)
        len = BUF_SIZE - 1;

    if (copy_from_user(buffer, buf, len))
        return -EFAULT;

    buffer[len] = '\0';
    *offset = 0;

    return len;
}

static struct file_operations fops = {
    .owner   = THIS_MODULE,
    .open    = dev_open,
    .release = dev_release,
    .read    = simple_read,
    .write   = simple_write,
};



static int __init simple_init(void)
{
    int ret;


    ret = alloc_chrdev_region(&devnum, 0, 1, DEVICE_NAME);
    if (ret < 0) {
        pr_err("simplechar: alloc_chrdev_region failed\n");
        return ret;
    }

    pr_info("simplechar: Major=%d Minor=%d\n", MAJOR(devnum), MINOR(devnum));

    cdev_init(&cdev_obj, &fops);
    ret = cdev_add(&cdev_obj,devnum,1);
    class = class_create(DEVICE_NAME);


    device_create(class, NULL, devnum, NULL, DEVICE_NAME);
    pr_info("simplechar: driver loaded successfully\n");
    return 0;
}



static void __exit simple_exit(void)
{
    device_destroy(class, devnum);
    class_destroy(class);
    cdev_del(&cdev_obj);
    unregister_chrdev_region(devnum, 1);

    pr_info("simplechar: driver unloaded\n");
}

module_init(simple_init);
module_exit(simple_exit);

