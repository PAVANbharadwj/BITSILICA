#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init test_oops_init(void)
{
    printk(KERN_INFO "In init: %s\n", __func__);

    printk(KERN_INFO "We are trying to access invalid memory location...\n");

    *(int *)0x12 = 'A';   // Invalid write → OOPS

    return 0;
}

static void __exit test_oops_exit(void)
{
    printk(KERN_INFO "In exit: %s\n", __func__);
}

module_init(test_oops_init);
module_exit(test_oops_exit);

