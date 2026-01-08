#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/atomic.h>
#include <linux/delay.h>
#include <linux/ioctl.h>


#define DEVICE_NAME  "smartLED"
#define CLASS_NAME   "smartclass"

#define SMART_LIGHT_MAGIC 'L'
#define IOCTL_TURN_ON            _IO(SMART_LIGHT_MAGIC, 1)
#define IOCTL_TURN_OFF           _IO(SMART_LIGHT_MAGIC, 2)
#define IOCTL_SET_BRIGHTNESS     _IOW(SMART_LIGHT_MAGIC, 3, int)
#define IOCTL_SET_TEMPERATURE    _IOW(SMART_LIGHT_MAGIC, 4, int)
#define IOCTL_SMOOTH_BRIGHTNESS  _IOW(SMART_LIGHT_MAGIC, 5, int)
#define IOCTL_GET_STATE          _IOR(SMART_LIGHT_MAGIC, 6, struct light_state_user)

struct light_state_user {
    int brightness;
    int temperature;
    int is_on;
};


struct light_state {
    atomic_t brightness;     
    atomic_t temperature;    
    atomic_t is_on;          
    atomic_t active_users;
};

static struct light_state bulb;


static dev_t dev_num;
static struct cdev sl_cdev;
static struct class *sl_class;
static struct device *sl_device;


static int sl_open(struct inode *inode, struct file *file)
{
    atomic_inc(&bulb.active_users);
    return 0;
}


static int sl_release(struct inode *inode, struct file *file)
{
    atomic_dec(&bulb.active_users);
    return 0;
}


static long sl_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    int val;
    struct light_state_user usr_state;

    switch (cmd) {

    case IOCTL_TURN_ON:
        atomic_set(&bulb.is_on, 1);
        break;

    case IOCTL_TURN_OFF:
        atomic_set(&bulb.is_on, 0);
        break;

    case IOCTL_SET_BRIGHTNESS:
        if (copy_from_user(&val, (int __user *)arg, sizeof(int)))
            return -EFAULT;

        if (val < 0) val = 0;
        if (val > 100) val = 100;

        atomic_set(&bulb.brightness, val);
        break;

    case IOCTL_SET_TEMPERATURE:
        if (copy_from_user(&val, (int __user *)arg, sizeof(int)))
            return -EFAULT;

        if (val < 2000) val = 2000;
        if (val > 6500) val = 6500;

        atomic_set(&bulb.temperature, val);
        break;

    case IOCTL_SMOOTH_BRIGHTNESS:
    {
        int curr_b = atomic_read(&bulb.brightness);

        if (copy_from_user(&val, (int __user *)arg, sizeof(int)))
            return -EFAULT;

        if (val < 0) val = 0;
        if (val > 100) val = 100;

        if (curr_b < val) {
            int i;
            for (i = curr_b; i <= val; i++) {
                atomic_set(&bulb.brightness, i);
                msleep(10);
            }
        } else {
            int i;
            for (i = curr_b; i >= val; i--) {
                atomic_set(&bulb.brightness, i);
                msleep(10);
            }
        }
    }
    break;

    case IOCTL_GET_STATE:
        usr_state.brightness  = atomic_read(&bulb.brightness);
        usr_state.temperature = atomic_read(&bulb.temperature);
        usr_state.is_on       = atomic_read(&bulb.is_on);

        if (copy_to_user((void __user *)arg, &usr_state, sizeof(usr_state)))
            return -EFAULT;
        break;

    default:
        return -EINVAL;
    }

    return 0;
}


static const struct file_operations sl_fops = {
    .owner          = THIS_MODULE,
    .open           = sl_open,
    .release        = sl_release,
    .unlocked_ioctl = sl_ioctl,
};

static int __init sl_init(void)
{
    atomic_set(&bulb.brightness, 0);
    atomic_set(&bulb.temperature, 3000);
    atomic_set(&bulb.is_on, 0);
    atomic_set(&bulb.active_users, 0);

    alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);

    cdev_init(&sl_cdev, &sl_fops);
    cdev_add(&sl_cdev, dev_num, 1);

    sl_class = class_create(CLASS_NAME);
    sl_device = device_create(sl_class, NULL, dev_num, NULL, DEVICE_NAME);

    pr_info("Smart LED\n");
    return 0;
}


static void __exit sl_exit(void)
{
    device_destroy(sl_class, dev_num);
    class_destroy(sl_class);

    cdev_del(&sl_cdev);
    unregister_chrdev_region(dev_num, 1);

    pr_info("Smart LED\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavan");
MODULE_DESCRIPTION("Smart LED");

module_init(sl_init);
module_exit(sl_exit);

