#include<linux/module.h>
#include<linux/kernel.h>


MODULE_LICENSE("GPL");
static int __init test_hello2_init(void){
        printk(KERN_INFO "%s: In init\n",__func__);
        return 0;
}

static void __exit test_hello2_exit(void){
        printk(KERN_INFO "%s: In exit\n",__func__);
}

module_init(test_hello2_init);
module_exit(test_hello2_exit);
