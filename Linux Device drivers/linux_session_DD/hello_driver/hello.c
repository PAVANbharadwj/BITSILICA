#include <linux/init.h>      // for __init and __exit macros
#include <linux/module.h>    // for all kernel modules
#include <linux/kernel.h>    // for pr_info()

MODULE_LICENSE("GPL");
MODULE_AUTHOR("YourName");
MODULE_DESCRIPTION("Simple Hello World driver");
MODULE_VERSION("1.0");

static int __init hello_init(void)
{
    pr_info("hello_driver: Hello, kernel! This is my first driver.\n");
    return 0;   // 0 means success
}

static void __exit hello_exit(void)
{
    pr_info("hello_driver: Goodbye, kernel! Driver is being unloaded.\n");
}

module_init(hello_init);
module_exit(hello_exit);

