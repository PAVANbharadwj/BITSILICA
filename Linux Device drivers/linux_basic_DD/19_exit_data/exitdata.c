#include<linux/module.h>
#include<linux/init.h>



static int exit_counter __exitdata = 0;

static void __exit my_exit(void)
{
    exit_counter++;
    printk(KERN_INFO "Exit counter = %d\n", exit_counter);
}

static int __init my_init(void)
{
    printk(KERN_INFO "Module Loaded\n");
    return 0;
}

module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");

