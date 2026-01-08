#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init test_panic_init(void)
{
    printk(KERN_INFO "In init: %s\n", __func__);

    // Trigger panic
    panic("Hello Kernel, I am causing the panic!\n");

    return 0;   // This will never be reached
}

static void __exit test_panic_exit(void)
{
    printk(KERN_INFO "In exit: %s\n", __func__);
}

module_init(test_panic_init);
module_exit(test_panic_exit);

