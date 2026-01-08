#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init my_init(void)
{
    int i;

    for (i = 0; i < 10; i++) {
        pr_info_once("This message prints only once!\n");
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

