#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include<linux/spinlock.h>
#include<linux/mutex.h>

#define DRIVER_NAME "pcd_device"
#define CLASS_NAME  "pcd_class"
#define BUF_SIZE    1024

static dev_t dev_num;
static struct cdev my_cdev;
static struct class *my_class;
static struct device *my_device;

/* Device buffer */
static char device_buffer[BUF_SIZE];
static size_t data_size;

//static DEFINE_SPINLOCK(pcd_spin_lock);
static DEFINE_MUTEX(pcd_mutex_lock);

/* ---------------- File Operations ---------------- */

static int my_open(struct inode *inode, struct file *file)
{
    pr_info("device opened\n");
    return 0;
}

static int my_release(struct inode *inode, struct file *file)
{
    pr_info("device closed\n");
    return 0;
}

static ssize_t my_read(struct file *file,
                       char __user *buf,
                       size_t len,
                       loff_t *off)
{

   if(mutex_lock_interruptible(&pcd_mutex_lock)){
                return -EINTR;
    }

    size_t bytes;

    pr_info("requested read\n");

    if (*off < 0)
        return -EINVAL;

    if (*off >= data_size)
        return 0;   /* EOF */

    bytes = min_t(size_t, len, data_size - *off);

    if (copy_to_user(buf, device_buffer + *off, bytes))
        return -EFAULT;

    *off += bytes;
    mutex_unlock(&pcd_mutex_lock);
    return bytes;
}

static ssize_t my_write(struct file *file,
                        const char __user *buf,
                        size_t len,
                        loff_t *off)
{


    if(mutex_lock_interruptible(&pcd_mutex_lock)){
		return -EINTR;
    }

    size_t bytes;
    size_t available;

    pr_info("requested write\n");

    if (*off < 0)
        return -EINVAL;

    if (*off >= BUF_SIZE)
        return -ENOSPC;

    available = BUF_SIZE - *off;
    bytes = min_t(size_t, len, available);

    if (copy_from_user(device_buffer + *off, buf, bytes))
        return -EFAULT;

    *off += bytes;
    data_size = max(data_size, (size_t)*off);



    mutex_unlock(&pcd_mutex_lock);
    return bytes;
}


static loff_t my_llseek(struct file *file,
                        loff_t offset,
                        int whence)
{
    loff_t new_pos;

    switch (whence) {
    case SEEK_SET:
        new_pos = offset;
        break;

    case SEEK_CUR:
        new_pos = file->f_pos + offset;
        break;

    case SEEK_END:
        new_pos = data_size + offset;
        break;

    default:
        return -EINVAL;
    }

    if (new_pos < 0 || new_pos > BUF_SIZE)
        return -EINVAL;

    file->f_pos = new_pos;
    pr_info("llseek: new position = %lld\n", new_pos);

    return new_pos;
}

/* file_operations */
static struct file_operations fops = {
    .owner   = THIS_MODULE,
    .open    = my_open,
    .release = my_release,
    .read    = my_read,
    .write   = my_write,
    .llseek  = my_llseek,
};

/* ---------------- Module Init ---------------- */

static int __init simple_char_init(void)
{
    int ret;

    /* Allocate major/minor */
    ret = alloc_chrdev_region(&dev_num, 0, 1, DRIVER_NAME);
    if (ret)
        return ret;

    /* Initialize cdev */
    cdev_init(&my_cdev, &fops);
    my_cdev.owner = THIS_MODULE;

    /* Add cdev */
    ret = cdev_add(&my_cdev, dev_num, 1);
    if (ret)
        goto err_cdev;

    /* Create class */
    my_class = class_create(CLASS_NAME);
    if (IS_ERR(my_class)) {
        ret = PTR_ERR(my_class);
        goto err_class;
    }

    /* Create device node */
    my_device = device_create(my_class, NULL, dev_num, NULL, DRIVER_NAME);
    if (IS_ERR(my_device)) {
        ret = PTR_ERR(my_device);
        goto err_device;
    }

    pr_info("simple_char loaded (major=%d minor=%d)\n",
            MAJOR(dev_num), MINOR(dev_num));
    return 0;

err_device:
    class_destroy(my_class);
err_class:
    cdev_del(&my_cdev);
err_cdev:
    unregister_chrdev_region(dev_num, 1);
    return ret;
}

/* ---------------- Module Exit ---------------- */

static void __exit simple_char_exit(void)
{
    device_destroy(my_class, dev_num);
    class_destroy(my_class);
    cdev_del(&my_cdev);
    unregister_chrdev_region(dev_num, 1);
    pr_info("simple_char unloaded\n");
}

module_init(simple_char_init);
module_exit(simple_char_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("You");
MODULE_DESCRIPTION("Simple character device driver with read/write/llseek");

