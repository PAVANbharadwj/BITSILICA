#include <linux/module.h>
#include <linux/kernel.h>

/* Declare the function exported by moduleA */
extern void hello_function(void);

static int __init modB_init(void)
{
    pr_info("Module B loaded\n");
    hello_function();    // Call function from moduleA
    return 0;
}

static void __exit modB_exit(void)
{
    pr_info("Module B removed\n");
}

module_init(modB_init);
module_exit(modB_exit);

MODULE_LICENSE("GPL");

