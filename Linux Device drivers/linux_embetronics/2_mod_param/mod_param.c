#include<linux/kernel.h>
#include<linux/moduleparam.h>
#include<linux/module.h>
#include<linux/init.h>

int value = 10;
char *name = "pavan";
int arr[5] = {1,2,3,4,5};
int count =5;

module_param(value,int,0644);
module_param(name,charp,0644);
module_param_array(arr,int,&count,0644);

static int __init my_init(void){
	printk("Module loaded");
	pr_info("value = %d",value);
	pr_info("Name = %s",name);
	for(int i = 0;i<count;i++){
		pr_info("arr[%d] = %d",i,arr[i]);
	}
	return 0;
}
static void __exit my_exit(void){
	printk("Module unloaded");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");



