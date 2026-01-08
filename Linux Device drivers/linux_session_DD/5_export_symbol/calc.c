#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

static int a = 10;
static int b =20;

MODULE_LICENSE("GPL");

extern int add(int, int);
extern int sub(int, int);
extern int mul(int, int);
extern int div(int, int);

static int __init my_init(void)
{
	pr_info("Addition : %d\n",add(a,b));
	pr_info("Multiplication : %d\n",mul(a,b));
	pr_info("subtraction : %d\n",sub(a,b));
	pr_info("Division: %d\n",div(a,b));
	return 0;
}
static void __exit my_exit(void)
{
	pr_info("Module Removed\n");
}

module_init(my_init);
module_exit(my_exit);


