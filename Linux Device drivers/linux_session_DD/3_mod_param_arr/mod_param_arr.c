#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
MODULE_LICENSE("GPL");

static int arr[5] = {1,2,3,4,5};
static int count = 5;

module_param_array(arr,int,&count,0644);

static int __init my_init(void){
	int i;
	pr_info("user gave %d values\n",count);
	for(i=0;i<count;i++){
		pr_info("%d ",arr[i]);
	}
	return 0;
}

static void __exit my_exit(void){
	pr_info("Array module removed");
}

module_init(my_init);
module_exit(my_exit);


