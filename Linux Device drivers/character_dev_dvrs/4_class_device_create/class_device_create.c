#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/kdev_t.h>

MODULE_LICENSE("GPL");

static struct class *myclass;
static struct device *device1, *device2;

dev_t dev1, dev2;

static int test_hello_init(void)
{
    /* Assign device numbers manually */
    dev1 = MKDEV(200, 1);
    dev2 = MKDEV(200, 2);

    /* Create a device class */
    myclass = class_create("my_classs_device");
    if (IS_ERR(myclass)) {
        printk(KERN_ERR "Class creation failed\n");
        return PTR_ERR(myclass);
    }

    /* Create device file: /dev/mydevice1 */
    device1 = device_create(myclass, NULL, dev1, NULL, "my_device_create%d", 1);
    if (IS_ERR(device1)) {
        printk(KERN_ERR "Device1 creation failed\n");
        class_destroy(myclass);
        return PTR_ERR(device1);
    }

    /* Create device file: /dev/mydevice2 */
    device2 = device_create(myclass, NULL, dev2, NULL, "my_device_create%d", 2);
    if (IS_ERR(device2)) {
        printk(KERN_ERR "Device2 creation failed\n");
        device_destroy(myclass, dev1);
        class_destroy(myclass);
        return PTR_ERR(device2);
    }

    printk(KERN_INFO "Device files created: /dev/mydevice1 and /dev/mydevice2\n");
    return 0;
}

static void test_hello_exit(void)
{
    device_destroy(myclass, dev1);
    device_destroy(myclass, dev2);

    class_destroy(myclass);

    printk(KERN_INFO "Device files removed and class destroyed\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);

