#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int value = 10;
static char *name = "Pavan";

/* Expose parameters */
module_param(value, int, 0644);
MODULE_PARM_DESC(value, "An integer value");

module_param(name, charp, 0644);
MODULE_PARM_DESC(name, "A string parameter");

static int __init my_init(void)
{
    pr_info("Module loaded\n");
    pr_info("value = %d\n", value);
    pr_info("name  = %s\n", name);
    return 0;
}

static void __exit my_exit(void)
{
    pr_info("Module removed\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");

