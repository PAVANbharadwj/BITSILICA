#include <linux/module.h>
#include <linux/kernel.h>

void hello_function(void)
{
    pr_info("Hello from exported function!\n");
}
EXPORT_SYMBOL(hello_function);   // Make it available to other modules
// EXPORT_SYMBOL_GPL(hello_function);  // GPL-only version

static int __init modA_init(void)
{
    pr_info("Module A loaded\n");
    return 0;
}

static void __exit modA_exit(void)
{
    pr_info("Module A removed\n");
}

module_init(modA_init);
module_exit(modA_exit);

MODULE_LICENSE("GPL");

