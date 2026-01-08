#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>

/* ---------------- Macros ---------------- */

#define DRIVER_NAME "pcd_n_devices"
#define CLASS_NAME  "pcd_n_class"
#define NO_OF_DEVICES 4

#define RDONLY  0x1
#define WRONLY  0x10
#define RDWR    0x11

#define MEM_SIZE_MAX_PCDEV1 1024
#define MEM_SIZE_MAX_PCDEV2 512
#define MEM_SIZE_MAX_PCDEV3 1024
#define MEM_SIZE_MAX_PCDEV4 512

/* ---------------- Pseudo device memory ---------------- */

static char device_buffer_pcdev1[MEM_SIZE_MAX_PCDEV1];
static char device_buffer_pcdev2[MEM_SIZE_MAX_PCDEV2];
static char device_buffer_pcdev3[MEM_SIZE_MAX_PCDEV3];
static char device_buffer_pcdev4[MEM_SIZE_MAX_PCDEV4];

/* ---------------- Device private data ---------------- */

struct pcdev_private_data {
    char *buffer;
    unsigned size;
    const char *serial_number;
    int perm;
    struct cdev cdev;
};

/* ---------------- Driver private data ---------------- */

struct pcdrv_private_data {
    int total_devices;
    dev_t device_number;
    struct class *class_pcd;
    struct pcdev_private_data pcdev_data[NO_OF_DEVICES];
};

/* ---------------- Static initialization ---------------- */

static struct pcdrv_private_data pcdrv_data = {
    .total_devices = NO_OF_DEVICES,
    .pcdev_data = {
        [0] = {
            .buffer = device_buffer_pcdev1,
            .size = MEM_SIZE_MAX_PCDEV1,
            .serial_number = "PCDEV1XYZ123",
            .perm = RDONLY,
        },
        [1] = {
            .buffer = device_buffer_pcdev2,
            .size = MEM_SIZE_MAX_PCDEV2,
            .serial_number = "PCDEV2XYZ123",
            .perm = WRONLY,
        },
        [2] = {
            .buffer = device_buffer_pcdev3,
            .size = MEM_SIZE_MAX_PCDEV3,
            .serial_number = "PCDEV3XYZ123",
            .perm = RDWR,
        },
        [3] = {
            .buffer = device_buffer_pcdev4,
            .size = MEM_SIZE_MAX_PCDEV4,
            .serial_number = "PCDEV4XYZ123",
            .perm = RDONLY,
        },
    }
};

/* ---------------- Permission check ---------------- */

static int check_permission(int dev_perm, int acc_mode)
{
    if (dev_perm == RDWR)
        return 0;

    if ((dev_perm == RDONLY) && (acc_mode & FMODE_WRITE))
        return -EPERM;

    if ((dev_perm == WRONLY) && (acc_mode & FMODE_READ))
        return -EPERM;

    return 0;
}

/* ---------------- File operations ---------------- */

static int pcd_open(struct inode *inode, struct file *filp)
{
    int minor;
    int ret;
    struct pcdev_private_data *dev_data;

    minor = MINOR(inode->i_rdev);
    dev_data = &pcdrv_data.pcdev_data[minor];
    filp->private_data = dev_data;

    ret = check_permission(dev_data->perm, filp->f_mode);
    if (ret)
        return ret;

    pr_info("pcd: device %d opened (serial=%s)\n",
            minor, dev_data->serial_number);
    return 0;
}

static int pcd_release(struct inode *inode, struct file *filp)
{
    pr_info("pcd: device closed\n");
    return 0;
}

static ssize_t pcd_read(struct file *filp,
                        char __user *buf,
                        size_t count,
                        loff_t *f_pos)
{
    struct pcdev_private_data *dev_data = filp->private_data;
    size_t bytes;

    if (*f_pos >= dev_data->size)
        return 0;

    bytes = min_t(size_t, count, dev_data->size - *f_pos);

    if (copy_to_user(buf, dev_data->buffer + *f_pos, bytes))
        return -EFAULT;

    *f_pos += bytes;
    return bytes;
}

static ssize_t pcd_write(struct file *filp,
                         const char __user *buf,
                         size_t count,
                         loff_t *f_pos)
{
    struct pcdev_private_data *dev_data = filp->private_data;
    size_t bytes;

    if (*f_pos >= dev_data->size)
        return -ENOSPC;

    bytes = min_t(size_t, count, dev_data->size - *f_pos);

    if (copy_from_user(dev_data->buffer + *f_pos, buf, bytes))
        return -EFAULT;

    *f_pos += bytes;
    return bytes;
}

static loff_t pcd_llseek(struct file *filp,
                         loff_t offset,
                         int whence)
{
    struct pcdev_private_data *dev_data = filp->private_data;
    loff_t new_pos;

    switch (whence) {
    case SEEK_SET:
        new_pos = offset;
        break;
    case SEEK_CUR:
        new_pos = filp->f_pos + offset;
        break;
    case SEEK_END:
        new_pos = dev_data->size + offset;
        break;
    default:
        return -EINVAL;
    }

    if (new_pos < 0 || new_pos > dev_data->size)
        return -EINVAL;

    filp->f_pos = new_pos;
    return new_pos;
}

static struct file_operations pcd_fops = {
    .owner   = THIS_MODULE,
    .open    = pcd_open,
    .release = pcd_release,
    .read    = pcd_read,
    .write   = pcd_write,
    .llseek  = pcd_llseek,
};

/* ---------------- Driver init ---------------- */

static int __init pcd_driver_init(void)
{
    int ret, i;

    ret = alloc_chrdev_region(&pcdrv_data.device_number,
                              0, NO_OF_DEVICES, DRIVER_NAME);
    if (ret)
        return ret;

    pcdrv_data.class_pcd = class_create(CLASS_NAME);
    if (IS_ERR(pcdrv_data.class_pcd)) {
        ret = PTR_ERR(pcdrv_data.class_pcd);
        goto unreg_chrdev;
    }

    for (i = 0; i < NO_OF_DEVICES; i++) {

        pr_info("pcd: device %d major=%d minor=%d\n",
                i,
                MAJOR(pcdrv_data.device_number + i),
                MINOR(pcdrv_data.device_number + i));

        cdev_init(&pcdrv_data.pcdev_data[i].cdev, &pcd_fops);
        pcdrv_data.pcdev_data[i].cdev.owner = THIS_MODULE;

        ret = cdev_add(&pcdrv_data.pcdev_data[i].cdev,
                       pcdrv_data.device_number + i, 1);
        if (ret)
            goto cdev_del;

        device_create(pcdrv_data.class_pcd, NULL,
                      pcdrv_data.device_number + i,
                      NULL, "pcd-%d", i);
    }

    pr_info("pcd driver loaded\n");
    return 0;

cdev_del:
    while (--i >= 0) {
        device_destroy(pcdrv_data.class_pcd,
                       pcdrv_data.device_number + i);
        cdev_del(&pcdrv_data.pcdev_data[i].cdev);
    }
    class_destroy(pcdrv_data.class_pcd);

unreg_chrdev:
    unregister_chrdev_region(pcdrv_data.device_number, NO_OF_DEVICES);
    return ret;
}

/* ---------------- Driver exit ---------------- */

static void __exit pcd_driver_exit(void)
{
    int i;

    for (i = 0; i < NO_OF_DEVICES; i++) {
        device_destroy(pcdrv_data.class_pcd,
                       pcdrv_data.device_number + i);
        cdev_del(&pcdrv_data.pcdev_data[i].cdev);
    }

    class_destroy(pcdrv_data.class_pcd);
    unregister_chrdev_region(pcdrv_data.device_number, NO_OF_DEVICES);

    pr_info("pcd driver unloaded\n");
}

module_init(pcd_driver_init);
module_exit(pcd_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("You");
MODULE_DESCRIPTION("Pseudo Character Driver with multiple device nodes");

