#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "simplechar"
#define BUF_SIZE 100

static dev_t dev;
static struct cdev cdev_obj;

static char buffer[BUF_SIZE];
static int data_len = 0;

static ssize_t simple_read(struct file *file, char __user *user_buf,
                           size_t count, loff_t *ppos)
{
    if (*ppos >= data_len)
        return 0;  // EOF

    if (count > data_len - *ppos)
        count = data_len - *ppos;

    if (copy_to_user(user_buf, buffer + *ppos, count))
        return -EFAULT;

    *ppos += count;
    return count;
}

static ssize_t simple_write(struct file *file, const char __user *user_buf,
                            size_t count, loff_t *ppos)
{
    if (count > BUF_SIZE)
        count = BUF_SIZE;

    if (copy_from_user(buffer, user_buf, count))
        return -EFAULT;

    data_len = count;
    return count;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read  = simple_read,
    .write = simple_write,
};

static int __init simple_init(void)
{
    alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME);

    cdev_init(&cdev_obj, &fops);
    cdev_add(&cdev_obj, dev, 1);
    device_create

    pr_info("simplechar loaded: major=%d\n", MAJOR(dev));
    return 0;
}

static void __exit simple_exit(void)
{
    cdev_del(&cdev_obj);
    unregister_chrdev_region(dev, 1);
    pr_info("simplechar unloaded\n");
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");

