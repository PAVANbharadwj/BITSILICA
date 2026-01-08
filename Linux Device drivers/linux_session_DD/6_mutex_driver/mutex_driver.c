#include<linux/mutex.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include<linux/cdev.h>
#include<linux/kernel.h>

#define DEVICE_NAME "mutexdev"

static dev_t dev;
static struct cdev c_dev;
static struct class *cl;

static char device_buffer[100] = "Hello from mutex driver\n";

static DEFINE_MUTEX(my_mutex);

/* open */
static int my_open(struct inode *i, struct file *f)
{
    printk(KERN_INFO "mutexdev: open called\n");

    /* Simple blocking lock */
    mutex_lock(&my_mutex);

    printk(KERN_INFO "mutexdev: mutex locked\n");
    return 0;
}

/* release */
static int my_release(struct inode *i, struct file *f)
{
    mutex_unlock(&my_mutex);
    printk(KERN_INFO "mutexdev: mutex unlocked\n");
    return 0;
}

/* read using copy_to_user */
static ssize_t my_read(struct file *f, char __user *buf,
                       size_t len, loff_t *off)
{
    size_t bytes_available;
    size_t bytes_to_copy;

    bytes_available = strlen(device_buffer) - *off;
    if (bytes_available <= 0)
        return 0;

    if (len > bytes_available)
        bytes_to_copy = bytes_available;
    else
        bytes_to_copy = len;

    if (copy_to_user(buf, device_buffer + *off, bytes_to_copy))
        return -EFAULT;

    *off += bytes_to_copy;
    return bytes_to_copy;
}

/* write using copy_from_user */
static ssize_t my_write(struct file *f, const char __user *buf,
                        size_t len, loff_t *off)
{
    if (len > sizeof(device_buffer) - 1)
        len = sizeof(device_buffer) - 1;

    if (copy_from_user(device_buffer, buf, len))
        return -EFAULT;

    device_buffer[len] = '\0';
    return len;
}

static struct file_operations fops =
{
    .owner = THIS_MODULE,
    .open = my_open,
    .release = my_release,
    .read = my_read,
    .write = my_write
};

static int __init my_init(void)
{
    printk(KERN_INFO "mutexdev: loaded\n");

    alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME);

    cl = class_create("mutexclass");
    device_create(cl, NULL, dev, NULL, DEVICE_NAME);

    cdev_init(&c_dev, &fops);
    cdev_add(&c_dev, dev, 1);

    return 0;
}

static void __exit my_exit(void)
{
    cdev_del(&c_dev);
    device_destroy(cl, dev);
    class_destroy(cl);
    unregister_chrdev_region(dev, 1);

    printk(KERN_INFO "mutexdev: unloaded\n");
}
module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");
