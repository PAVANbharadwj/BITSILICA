#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

MODULE_LICENSE("GPL");
int add(int a,int b){
	return a+b;
}
EXPORT_SYMBOL(add);

int mul(int a,int b){
        return a*b;
}
EXPORT_SYMBOL(mul);

int sub(int a,int b){
        return a-b;
}
EXPORT_SYMBOL(sub);

int div(int a,int b){
	if(b==0){
		return 0;
	}
        return a+b;
}
EXPORT_SYMBOL(div);

static int __init my_init(void){
	pr_info("Module loaded\n");
	return 0;
}
static void __exit my_exit(void){
	pr_info("module removed\n");
}

module_init(my_init);
module_exit(my_exit);


