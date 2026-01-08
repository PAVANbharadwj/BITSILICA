#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ChatGPT");
MODULE_DESCRIPTION("Simple char device with ioctl (set/get int)");

#define DEVICE_NAME "simple_ioctl"

#define IOCTL_MAGIC 'k'
#define IOCTL_SET_VAL _IOW(IOCTL_MAGIC, 0, int)
#define IOCTL_GET_VAL _IOR(IOCTL_MAGIC, 1, int)
#define IOCTL_CLEAR   _IO(IOCTL_MAGIC, 2)

static dev_t dev_number;
static struct cdev my_cdev;
static struct class *my_class;
static int stored_value = 0;

static int fl_open(struct inode *inode, struct file *file)
{
    pr_info("simple_ioctl: open\n");
    return 0;
}

static int simple_release(struct inode *inode, struct file *file)
{
    pr_info("simple_ioctl: release\n");
    return 0;
}

static long simple_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    int val;

    switch (cmd) {
    case IOCTL_SET_VAL:
        if (copy_from_user(&val, (int __user *)arg, sizeof(int)))
            return -EFAULT;
        stored_value = val;
        pr_info("simple_ioctl: set value = %d\n", stored_value);
        break;

    case IOCTL_GET_VAL:
        val = stored_value;
        if (copy_to_user((int __user *)arg, &val, sizeof(int)))
            return -EFAULT;
        pr_info("simple_ioctl: get value = %d\n", stored_value);
        break;

    case IOCTL_CLEAR:
        stored_value = 0;
        pr_info("simple_ioctl: cleared value\n");
        break;

    default:
        return -ENOTTY;
    }
    return 0;
}

static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = fl_open,
    .release = simple_release,
    .unlocked_ioctl = simple_ioctl,
};

static int __init simple_init(void)
{
    int ret;

    ret = alloc_chrdev_region(&dev_number, 0, 1, DEVICE_NAME);
    if (ret) {
        pr_err("simple_ioctl: failed to alloc chrdev region\n");
        return ret;
    }

    cdev_init(&my_cdev, &fops);
    my_cdev.owner = THIS_MODULE;

    ret = cdev_add(&my_cdev, dev_number, 1);
    if (ret) {
        pr_err("simple_ioctl: cdev_add failed\n");
        unregister_chrdev_region(dev_number, 1);
        return ret;
    }

    my_class = class_create("simple_ioctl_class");
    if (IS_ERR(my_class)) {
        pr_err("simple_ioctl: class_create failed\n");
        cdev_del(&my_cdev);
        unregister_chrdev_region(dev_number, 1);
        return PTR_ERR(my_class);
    }

    device_create(my_class, NULL, dev_number, NULL, DEVICE_NAME);

    pr_info("simple_ioctl: loaded (major=%d minor=%d)\n", MAJOR(dev_number), MINOR(dev_number));
    return 0;
}

static void __exit simple_exit(void)
{
    device_destroy(my_class, dev_number);
    class_destroy(my_class);
    cdev_del(&my_cdev);
    unregister_chrdev_region(dev_number, 1);
    pr_info("simple_ioctl: unloaded\n");
}

module_init(simple_init);
module_exit(simple_exit);


