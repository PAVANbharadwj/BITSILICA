#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");


static int name = 10;
module_param_named(var,name,int,0644);



static int __init my_init(void)
{
	pr_info("the variable is %d\n" ,name);
	return 0;
}

static void __exit my_exit(void){
	pr_info("Module removed\n");
}

module_init(my_init);
module_exit(my_exit);



