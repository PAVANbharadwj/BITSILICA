#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");

static int base_minor = 0;
static int count = 1;
static char *device_name = "my_device";

module_param(base_minor, int, 0);
module_param(count, int, 0);
module_param(device_name, charp, 0);

dev_t devicenumber;   // global so exit can use it

static int test_hello_init(void)
{
    printk(KERN_INFO "Minor Number : %d\n", base_minor);
    printk(KERN_INFO "Count        : %d\n", count);
    printk(KERN_INFO "Device Name  : %s\n", device_name);

    /* allocate major dynamically */
    if (alloc_chrdev_region(&devicenumber, base_minor, count, device_name) == 0) {
        printk(KERN_INFO "Device number registered\n");
        printk(KERN_INFO "Major number received: %d\n", MAJOR(devicenumber));
        printk(KERN_INFO "Minor number assigned: %d\n", MINOR(devicenumber));
    } else {
        printk(KERN_ERR "Device number registration Failed\n");
    }

    return 0;
}

static void test_hello_exit(void)
{
    unregister_chrdev_region(devicenumber, count);
    printk(KERN_INFO "Device number unregistered\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);

