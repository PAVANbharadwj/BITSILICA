#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>

#define BUF_SIZE 100

static char buffer[BUF_SIZE];
static int data_len;

/* open */
static int misc_open(struct inode *inode, struct file *file)
{
    pr_info("misc: device opened\n");
    return 0;
}

/* release */
static int misc_release(struct inode *inode, struct file *file)
{
    pr_info("misc: device closed\n");
    return 0;
}

/* write */
static ssize_t misc_write(struct file *file,
                          const char __user *buf,
                          size_t len, loff_t *off)
{
    if (len > BUF_SIZE)
        len = BUF_SIZE;

    if (copy_from_user(buffer, buf, len))
        return -EFAULT;

    data_len = len;
    pr_info("misc: received %zu bytes\n", len);
    return len;
}

/* read */
static ssize_t misc_read(struct file *file,
                         char __user *buf,
                         size_t len, loff_t *off)
{
    if (*off >= data_len)
        return 0;

    if (len > data_len)
        len = data_len;

    if (copy_to_user(buf, buffer, len))
        return -EFAULT;

    *off += len;
    return len;
}

/* file operations */
static const struct file_operations misc_fops = {
    .owner   = THIS_MODULE,
    .open    = misc_open,
    .release = misc_release,
    .read    = misc_read,
    .write   = misc_write,
};

/* misc device structure */
static struct miscdevice misc_dev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name  = "miscdemo",
    .fops  = &misc_fops,
    .mode = 0666,
};

static int __init misc_init(void)
{
    misc_register(&misc_dev);
    pr_info("misc: driver registered\n");
    return 0;
}

static void __exit misc_exit(void)
{
    misc_deregister(&misc_dev);
    pr_info("misc: driver unregistered\n");
}

module_init(misc_init);
module_exit(misc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Example");
MODULE_DESCRIPTION("Simple misc device driver");

