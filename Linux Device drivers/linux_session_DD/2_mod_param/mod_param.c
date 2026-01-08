#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavan");
MODULE_DESCRIPTION("Simple module_param example");

static int myint = 10;
static char *mystring = "default";
static bool myflag = false;

module_param(myint, int, 0644);
module_param(mystring, charp, 0644);
module_param(myflag, bool, 0644);

static int __init mymodule_init(void)
{
    pr_info("myint = %d\n", myint);
    pr_info("mystring = %s\n", mystring);
    pr_info("myflag = %d\n", myflag);
    return 0;
}

static void __exit mymodule_exit(void)
{
    pr_info("Module removed\n");
}

module_init(mymodule_init);
module_exit(mymodule_exit);

