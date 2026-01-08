#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");

#define DEV_NAME "strlen_demo"
#define BUF_SIZE 64

static dev_t devnum;
static struct cdev cdev_obj;
static char kbuf[BUF_SIZE];

/* -------- WRITE: user → kernel -------- */
static ssize_t demo_write(struct file *file,
                          const char __user *buf,
                          size_t len, loff_t *off)
{
    size_t klen;

    /* ❌ WRONG (never do this) */
    /* strlen(buf);  // buf is user-space pointer */

    if (len >= BUF_SIZE)
        len = BUF_SIZE - 1;

    if (copy_from_user(kbuf, buf, len))
        return -EFAULT;

    kbuf[len] = '\0';   // ensure NULL-termination

    /* ✅ CORRECT: strlen on kernel buffer */
    klen = strlen(kbuf);

    pr_info("Kernel received: \"%s\"\n", kbuf);
    pr_info("Length using strlen() = %zu\n", klen);

    return len;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .write = demo_write,
};

static int __init demo_init(void)
{
    alloc_chrdev_region(&devnum, 0, 1, DEV_NAME);
    cdev_init(&cdev_obj, &fops);
    cdev_add(&cdev_obj, devnum, 1);

    pr_info("strlen_demo loaded (Major=%d)\n", MAJOR(devnum));
    return 0;
}

static void __exit demo_exit(void)
{
    cdev_del(&cdev_obj);
    unregister_chrdev_region(devnum, 1);
    pr_info("strlen_demo unloaded\n");
}

module_init(demo_init);
module_exit(demo_exit);

