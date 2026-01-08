#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include "mystruct.h"

MODULE_LICENSE("GPL");

static dev_t devnum;
static struct cdev cdev_obj;
static struct class *class;

static struct mydata *kernel_ptr;  // kernel heap pointer

/* ---------------- WRITE: user → kernel ---------------- */
static ssize_t heap_write(struct file *file, const char __user *buf,
                          size_t len, loff_t *off)
{
    if (len != sizeof(struct mydata))
        return -EINVAL;

    /* allocate in kernel heap */
    kernel_ptr = kmalloc(sizeof(struct mydata), GFP_KERNEL);
    if (!kernel_ptr)
        return -ENOMEM;

    /* copy user heap data to kernel heap */
    if (copy_from_user(kernel_ptr, buf, sizeof(struct mydata)))
        return -EFAULT;

    pr_info("Kernel received struct:\n");
    pr_info("id    = %d\n", kernel_ptr->id);
    pr_info("value = %d\n", kernel_ptr->value);
    pr_info("name  = %s\n", kernel_ptr->name);

    return sizeof(struct mydata);
}

/* ---------------- READ: kernel → user ---------------- */
static ssize_t heap_read(struct file *file, char __user *buf,
                         size_t len, loff_t *off)
{
    if (*off != 0 || !kernel_ptr)
        return 0;

    if (copy_to_user(buf, kernel_ptr, sizeof(struct mydata)))
        return -EFAULT;

    *off = sizeof(struct mydata);
    return sizeof(struct mydata);
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .write = heap_write,
    .read  = heap_read,
};










static int __init heap_init(void)
{
    alloc_chrdev_region(&devnum, 0, 1, "heapdev");

    cdev_init(&cdev_obj, &fops);
    cdev_add(&cdev_obj, devnum, 1);

    class = class_create("heapdev_class");


    device_create(class, NULL, devnum, NULL, "heapdev");

    pr_info("heapdev loaded: Major=%d\n", MAJOR(devnum));
    return 0;
}


static void __exit heap_exit(void)
{
    if (kernel_ptr)
        kfree(kernel_ptr);

    device_destroy(class, devnum);
    class_destroy(class);

    cdev_del(&cdev_obj);
    unregister_chrdev_region(devnum, 1);

    pr_info("heapdev unloaded\n");
}

module_init(heap_init);
module_exit(heap_exit);

