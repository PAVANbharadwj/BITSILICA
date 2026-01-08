#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");

static int major_number = 120;
static int minor_number = 0;
static int count = 1;
static char *device_name = "my_device";

module_param(major_number, int, 0);
module_param(minor_number, int, 0);
module_param(count, int, 0);
module_param(device_name, charp, 0);

dev_t devicenumber;   // Global so exit can unregister

static int test_hello_init(void)
{
    devicenumber = MKDEV(major_number, minor_number);

    printk(KERN_INFO "Major Number : %d\n", MAJOR(devicenumber));
    printk(KERN_INFO "Minor Number : %d\n", MINOR(devicenumber));
    printk(KERN_INFO "Count        : %d\n", count);
    printk(KERN_INFO "Device Name  : %s\n", device_name);

    if (register_chrdev_region(devicenumber, count, device_name) == 0)
        printk(KERN_INFO "Device number registered successfully\n");
    else
        printk(KERN_ERR "Device number registration FAILED\n");

    return 0;
}

static void test_hello_exit(void)
{
    unregister_chrdev_region(devicenumber, count);
    printk(KERN_INFO "Device number unregistered\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);

