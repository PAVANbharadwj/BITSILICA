#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");

#define DRIVER_NAME "multi_dev"
#define NUM_DEVS    3
#define BUF_SIZE    64

struct my_device {
    char buffer[BUF_SIZE];
    struct cdev cdev;
};

static dev_t dev_base;
static struct class *dev_class;
static struct my_device devices[NUM_DEVS];

/* ---------------- WRITE ---------------- */
static ssize_t my_write(struct file *file,
                        const char __user *buf,
                        size_t len, loff_t *off)
{
    int minor = iminor(file->f_inode);
    struct my_device *dev = &devices[minor];

    if (len >= BUF_SIZE)
        len = BUF_SIZE - 1;

    if (copy_from_user(dev->buffer, buf, len))
        return -EFAULT;

    dev->buffer[len] = '\0';

    pr_info("multi_dev%d received: %s\n", minor, dev->buffer);
    pr_info("strlen = %zu\n", strlen(dev->buffer));

    return len;
}

/* ---------------- READ ---------------- */
static ssize_t my_read(struct file *file,
                       char __user *buf,
                       size_t len, loff_t *off)
{
    int minor = iminor(file->f_inode);
    struct my_device *dev = &devices[minor];
    size_t data_len;

    if (*off != 0)
        return 0;

    data_len = strlen(dev->buffer);

    if (copy_to_user(buf, dev->buffer, data_len))
        return -EFAULT;

    *off = data_len;
    return data_len;
}

/* ---------------- FILE OPS ---------------- */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read  = my_read,
    .write = my_write,
};

/* permission fix */


/* ---------------- INIT ---------------- */
static int __init multi_init(void)
{
    int i;

    /* allocate MAJOR + 3 MINORS */
    alloc_chrdev_region(&dev_base, 0, NUM_DEVS, DRIVER_NAME);

    dev_class = class_create(DRIVER_NAME);

    for (i = 0; i < NUM_DEVS; i++) {
        cdev_init(&devices[i].cdev, &fops);
        cdev_add(&devices[i].cdev, dev_base + i, 1);

        device_create(dev_class, NULL,
                      dev_base + i, NULL,
                      "multi%d", i);
    }

    pr_info("multi_dev loaded: Major=%d\n", MAJOR(dev_base));
    return 0;
}

/* ---------------- EXIT ---------------- */
static void __exit multi_exit(void)
{
    int i;

    for (i = 0; i < NUM_DEVS; i++) {
        device_destroy(dev_class, dev_base + i);
        cdev_del(&devices[i].cdev);
    }

    class_destroy(dev_class);
    unregister_chrdev_region(dev_base, NUM_DEVS);

    pr_info("multi_dev unloaded\n");
}

module_init(multi_init);
module_exit(multi_exit);

