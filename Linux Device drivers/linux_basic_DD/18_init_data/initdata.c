


#include <linux/module.h>
#include <linux/init.h>
static int my_value __initdata = 10;

static int __init my_init(void)
{
    printk(KERN_INFO "Init value = %d\n", my_value);
    return 0;
}

static void __exit my_exit(void)
{
    printk(KERN_INFO "Module exit\n");
}

module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");

