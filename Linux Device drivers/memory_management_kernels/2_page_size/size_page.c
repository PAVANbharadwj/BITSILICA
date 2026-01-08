#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/mm_types.h>


MODULE_LICENSE("GPL");

static int __init hello_init(void){
	pr_info("size of page is %lu bytes",sizeof(struct page));
	return -1;
}
static void __exit hello_exit(void)
{
}

module_init(hello_init);
module_exit(hello_exit);

