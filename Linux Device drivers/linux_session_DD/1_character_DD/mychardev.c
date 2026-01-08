// mychardev.c
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "mychardev"
#define CLASS_NAME  "mychar"
#define BUF_LEN     1024

static int major;
static struct class *mychardev_class;
static struct cdev my_cdev;

/* Simple in-kernel buffer */
static char device_buffer[BUF_LEN];
static size_t data_size;  // how many bytes are valid in device_buffer

static int my_open(struct inode *inode, struct file *file)
{
    pr_info("mychardev: device opened\n");
    return 0;
}

static int my_release(struct inode *inode, struct file *file)
{
    pr_info("mychardev: device closed\n");
    return 0;
}

static ssize_t my_read(struct file *file, char __user *buf,
                       size_t len, loff_t *offset)
{
    size_t bytes_available;
    size_t bytes_to_copy;

    if (*offset >= data_size)
        return 0; /* EOF */

    bytes_available = data_size - *offset;
    bytes_to_copy   = (len > bytes_available) ? bytes_available : len;

    if (copy_to_user(buf, device_buffer + *offset, bytes_to_copy))
        return -EFAULT;

    *offset += bytes_to_copy;
    pr_info("mychardev: read %zu bytes\n", bytes_to_copy);

    return bytes_to_copy;
}

static ssize_t my_write(struct file *file, const char __user *buf,
                        size_t len, loff_t *offset)
{
    size_t bytes_to_copy;

    /* For simplicity, always overwrite from start */
    if (len > BUF_LEN)
        bytes_to_copy = BUF_LEN;
    else
        bytes_to_copy = len;

    if (copy_from_user(device_buffer, buf, bytes_to_copy))
        return -EFAULT;

    data_size = bytes_to_copy;
    *offset   = bytes_to_copy;

    pr_info("mychardev: wrote %zu bytes (user tried %zu)\n",
            bytes_to_copy, len);

    return bytes_to_copy;
}

static const struct file_operations fops = {
    .owner   = THIS_MODULE,
    .open    = my_open,
    .release = my_release,
    .read    = my_read,
    .write   = my_write,
};

static int __init mychardev_init(void)
{
    int ret;
    dev_t dev;
    struct device *dev_ret;

    /* Allocate a device number dynamically */
    ret = alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME);
    if (ret < 0) {
        pr_err("mychardev: failed to allocate chrdev region\n");
        return ret;
    }

    major = MAJOR(dev);

    /* Initialize cdev */
    cdev_init(&my_cdev, &fops);
    my_cdev.owner = THIS_MODULE;

    ret = cdev_add(&my_cdev, dev, 1);
    if (ret < 0) {
        pr_err("mychardev: cdev_add failed\n");
        unregister_chrdev_region(dev, 1);
        return ret;
    }

    /*
     * NOTE: On kernels >= 6.4 (including your 6.8.0-87),
     * class_create takes ONLY the class name string.
     */
    mychardev_class = class_create(CLASS_NAME);
    if (IS_ERR(mychardev_class)) {
        pr_err("mychardev: class_create failed\n");
        cdev_del(&my_cdev);
        unregister_chrdev_region(dev, 1);
        return PTR_ERR(mychardev_class);
    }

    /*
     * device_create() API is unchanged:
     * device_create(class, parent, devt, drvdata, "name");
     */
    dev_ret = device_create(mychardev_class, NULL, dev, NULL, DEVICE_NAME);
    if (IS_ERR(dev_ret)) {
        pr_err("mychardev: device_create failed\n");
        class_destroy(mychardev_class);
        cdev_del(&my_cdev);
        unregister_chrdev_region(dev, 1);
        return PTR_ERR(dev_ret);
    }

    data_size = 0;

    pr_info("mychardev: loaded, major=%d\n", major);
    pr_info("mychardev: device node should be /dev/%s\n", DEVICE_NAME);

    return 0;
}

static void __exit mychardev_exit(void)
{
    dev_t dev = MKDEV(major, 0);

    device_destroy(mychardev_class, dev);
    class_destroy(mychardev_class);
    cdev_del(&my_cdev);
    unregister_chrdev_region(dev, 1);

    pr_info("mychardev: unloaded\n");
}

module_init(mychardev_init);
module_exit(mychardev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavan’s test driver");
MODULE_DESCRIPTION("Simple character device with read/write buffer (kernel 6.8 API)");
MODULE_VERSION("1.0");

