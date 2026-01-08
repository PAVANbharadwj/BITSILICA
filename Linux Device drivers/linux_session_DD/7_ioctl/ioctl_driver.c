#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/uaccess.h>
#include<linux/fs.h>
#include<linux/cdev.h>

#define DEVICE_NAME "ioctl_driver"

static int value = 0;

#define IOC_MAGIC 'k'
#define IOCTL_SET_VALUE _IOW(IOC_MAGIC,1,int)
#define IOCTL_GET_VALUE _IOR(IOC_MAGIC,2,int)
#define IOCTL_CLEAR_VALUE _IO(IOC_MAGIC,3)


static dev_t dev;
static struct cdev c_dev;
static struct class *cl;


static long dev_ioctl(struct file *f, unsigned int cmd, unsigned long arg)
{
    int temp;

    switch(cmd)
    {
        case IOCTL_SET_VALUE:
            pr_info("Setting value\n");
            if(copy_from_user(&temp, (int*)arg, sizeof(temp))) {
                return -EFAULT;
            }
            value = temp;
            break;

        case IOCTL_GET_VALUE:
            pr_info("Getting value\n");
            if(copy_to_user((int*)arg, &value, sizeof(value))) {
                return -EFAULT;
            }
            break;

        case IOCTL_CLEAR_VALUE:
            pr_info("Clearing value\n");
            value = 0;
            break;

        default:
            return -EINVAL;
    }

    return 0;
}


static int device_open(struct inode *inode,struct file *file){
	printk(KERN_INFO "Device opened\n");
	return 0;
}

static int device_close(struct inode *inode,struct file *file){
	printk(KERN_INFO "Device closed\n");
	return 0;
}


static struct file_operations fops = 
{
	.owner = THIS_MODULE,
	.open = device_open,
	.release = device_close,
	.unlocked_ioctl = dev_ioctl,
};




static int __init my_init(void){
	if(alloc_chrdev_region(&dev,0,1,DEVICE_NAME)){
			return -1;
	}
	cl = class_create("ioctl_class");
	device_create(cl,NULL,dev,NULL,DEVICE_NAME);

	cdev_init(&c_dev,&fops);
	cdev_add(&c_dev,dev,1);

	pr_info("The module loaded successfully\n");
	return 0;
}

static void __exit my_exit(void){
	cdev_del(&c_dev);
	device_destroy(cl,dev);
	class_destroy(cl);
	unregister_chrdev_region(dev,1);

	pr_info("the module removed\n");

}



module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");




























