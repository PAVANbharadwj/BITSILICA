#include<linux/module.h>
#include<linux/init.h>


static int __init my_init(void){
	printk(KERN_INFO "Hello driver");
	return 0;
}
MODULE_LICENSE("GPL");

static void __exit my_exit(void){
	printk(KERN_INFO "Bye driver");
}

module_init(my_init);
module_exit(my_exit);


