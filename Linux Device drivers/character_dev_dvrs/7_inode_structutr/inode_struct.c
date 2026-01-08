#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");

#define DEVICE_NAME "inode_struct"
#define BUF_SIZE 1024

static dev_t devnum;
static struct cdev cdev_obj;
static struct class *class;

static char buffer[BUF_SIZE] = "Hello from kernel!\n";










static int dev_open(struct inode *inode, struct file *file)
{
    int major = imajor(inode);
    int minor = iminor(inode);

    pr_info("simplechar: %s called\n", __func__);
    pr_info("simplechar: Device opened → Major=%d Minor=%d\n", major, minor);


    switch (file->f_flags & O_ACCMODE) {

    case O_RDONLY:
        pr_info("Opened in READ-ONLY mode\n");
        break;

    case O_WRONLY:
        pr_info("Opened in WRITE-ONLY mode\n");
        break;

    case O_RDWR:
        pr_info("Opened in READ/WRITE mode\n");
        break;
    }


    if (file->f_flags & O_CREAT)    pr_info("O_CREAT → create if not exist\n");
    if (file->f_flags & O_EXCL)     pr_info("O_EXCL → exclusive create\n");
    if (file->f_flags & O_TRUNC)    pr_info("O_TRUNC → truncate file\n");
    if (file->f_flags & O_APPEND)   pr_info("O_APPEND → append mode\n");
    if (file->f_flags & O_NONBLOCK) pr_info("O_NONBLOCK → non-blocking\n");
    if (file->f_flags & O_SYNC)     pr_info("O_SYNC → sync writes\n");
    if (file->f_flags & O_DSYNC)    pr_info("O_DSYNC → data sync\n");
    



    pr_info("Mode            : %ho\n", inode->i_mode);
    pr_info("User ID         : %d\n", inode->i_uid.val);
    pr_info("Group ID        : %d\n", inode->i_gid.val);
    pr_info("Inode Number    : %lu\n", inode->i_ino);

    pr_info("Major:%d  Minor:%d   (via imajor/iminor)\n",
            imajor(inode), iminor(inode));

    pr_info("Major:%d  Minor:%d   (via i_rdev)\n",
            MAJOR(inode->i_rdev), MINOR(inode->i_rdev));



    return 0;
}


static int dev_release(struct inode *inode, struct file *file)
{
    pr_info("simplechar: device closed\n");
    return 0;
}


static ssize_t simple_read(struct file *file, char __user *buf,
                           size_t len, loff_t *offset)
{
    size_t remaining = strlen(buffer) - *offset;

    if (remaining == 0)
        return 0;

    if (len > remaining)
        len = remaining;

    if (copy_to_user(buf, buffer + *offset, len))
        return -EFAULT;

    *offset += len;
    return len;
}


static ssize_t simple_write(struct file *file, const char __user *buf,
                            size_t len, loff_t *offset)
{
    if (len > BUF_SIZE - 1)
        len = BUF_SIZE - 1;

    if (copy_from_user(buffer, buf, len))
        return -EFAULT;

    buffer[len] = '\0';
    *offset = 0;

    return len;
}


static struct file_operations fops = {
    .owner   = THIS_MODULE,
    .open    = dev_open,
    .release = dev_release,
    .read    = simple_read,
    .write   = simple_write,
};


static int __init simple_init(void)
{
    alloc_chrdev_region(&devnum, 0, 1, DEVICE_NAME);

    cdev_init(&cdev_obj, &fops);
    cdev_add(&cdev_obj, devnum, 1);

    class = class_create(DEVICE_NAME);


    device_create(class, NULL, devnum, NULL, DEVICE_NAME);

    pr_info("simplechar: driver loaded Major=%d\n", MAJOR(devnum));
    return 0;
}

static void __exit simple_exit(void)
{
    device_destroy(class, devnum);
    class_destroy(class);

    cdev_del(&cdev_obj);
    unregister_chrdev_region(devnum, 1);

    pr_info("simplechar: driver unloaded\n");
}

module_init(simple_init);
module_exit(simple_exit);

