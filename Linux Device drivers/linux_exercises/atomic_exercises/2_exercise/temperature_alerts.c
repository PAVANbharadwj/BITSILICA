#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/wait.h>
#include <linux/atomic.h>
#include <linux/mutex.h>
#include <linux/poll.h>

#define DEVICE_NAME "tempsensor"
#define CLASS_NAME  "tempcls"

#define MAX_HISTORY 10
#define DEBOUNCE_MS 200     

#define TEMP_IOCTL_MAGIC 'T'
#define TEMP_IOCTL_SET_HIGH _IOW(TEMP_IOCTL_MAGIC, 1, int)
#define TEMP_IOCTL_SET_LOW  _IOW(TEMP_IOCTL_MAGIC, 2, int)

struct temp_sensor {
    atomic_t current_temp;
    atomic_t high_threshold;
    atomic_t low_threshold;

    atomic_t alert_count;

    wait_queue_head_t alert_queue;

  
    int history[MAX_HISTORY];
    int hist_index;

    unsigned long last_alert_jiffies;

    struct mutex lock;
};

static struct temp_sensor sensor;

static dev_t dev;
static struct cdev cdev_t;
static struct class *cls;


static void temp_change(int new_temp)
{
    unsigned long now = jiffies;

    atomic_set(&sensor.current_temp, new_temp);


    if (time_before(now, sensor.last_alert_jiffies + msecs_to_jiffies(DEBOUNCE_MS)))
        return;

    int high = atomic_read(&sensor.high_threshold);
    int low  = atomic_read(&sensor.low_threshold);

    if (new_temp >= high || new_temp <= low) {
        sensor.last_alert_jiffies = now;


        sensor.history[sensor.hist_index] = new_temp;
        sensor.hist_index = (sensor.hist_index + 1) % MAX_HISTORY;

        atomic_inc(&sensor.alert_count);

        wake_up_interruptible(&sensor.alert_queue);
    }
}




static int temp_open(struct inode *inode, struct file *file)
{
    return 0;
}

static int temp_release(struct inode *inode, struct file *file)
{
    return 0;
}

static ssize_t temp_read(struct file *file, char __user *buf, size_t size, loff_t *off)
{
    int alert_id;


    wait_event_interruptible(sensor.alert_queue,
                             atomic_read(&sensor.alert_count) != 0);

    mutex_lock(&sensor.lock);
    alert_id = atomic_read(&sensor.alert_count); 
    atomic_set(&sensor.alert_count, 0);    

    mutex_unlock(&sensor.lock);

    if (copy_to_user(buf, &alert_id, sizeof(int)))
        return -EFAULT;

    return sizeof(int);
}



static long temp_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    int val;

    if (copy_from_user(&val, (int __user *)arg, sizeof(int)))
        return -EFAULT;

    switch (cmd) {
        case TEMP_IOCTL_SET_HIGH:
            atomic_set(&sensor.high_threshold, val);
            break;

        case TEMP_IOCTL_SET_LOW:
            atomic_set(&sensor.low_threshold, val);
            break;

        default:
            return -EINVAL;
    }
    return 0;
}

static const struct file_operations fops = {
    .owner          = THIS_MODULE,
    .open           = temp_open,
    .release        = temp_release,
    .read           = temp_read,
    .unlocked_ioctl = temp_ioctl,
 };


static int __init temp_init(void)
{
    int ret;

    atomic_set(&sensor.current_temp, 25);   // 25°C
    atomic_set(&sensor.high_threshold, 40);
    atomic_set(&sensor.low_threshold, 10);
    atomic_set(&sensor.alert_count, 0);

    init_waitqueue_head(&sensor.alert_queue);
    mutex_init(&sensor.lock);
    sensor.hist_index = 0;
    sensor.last_alert_jiffies = 0;


    if ((ret = alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME)) < 0)
        return ret;

    cdev_init(&cdev_t, &fops);
    if ((ret = cdev_add(&cdev_t, dev, 1)) < 0)
        return ret;

 
    cls = class_create(CLASS_NAME);
    if (IS_ERR(cls))
        return PTR_ERR(cls);

    device_create(cls, NULL, dev, NULL, DEVICE_NAME);

    pr_info("Temp Sensor Driver Loaded\n");


    temp_change(45);
    temp_change(5);

    return 0;
}

static void __exit temp_exit(void)
{
    device_destroy(cls, dev);
    class_destroy(cls);
    cdev_del(&cdev_t);
    unregister_chrdev_region(dev, 1);

    pr_info("Temp Sensor Driver Unloaded\n");
}

module_init(temp_init);
module_exit(temp_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Temperature Sensor with Threshold Alerts");
MODULE_AUTHOR("Pavan");

