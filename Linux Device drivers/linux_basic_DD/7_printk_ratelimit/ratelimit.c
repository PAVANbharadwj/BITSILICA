#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/ratelimit.h>

static int __init my_init(void)
{
    int i;

    pr_info("Module loaded: Testing printk_ratelimit\n");

    for (i = 0; i < 100; i++) {
        if (printk_ratelimit()) {
            pr_info("Message %d: This will be rate-limited\n", i);
        }
    }

    return 0;
}

static void __exit my_exit(void)
{
    pr_info("Module removed\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");

