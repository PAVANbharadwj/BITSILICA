#include<linux/module.h>
#include<linux/kernel.h>
#include<asm/io.h>

MODULE_LICENSE("GPL");
static int __init hello_init(void){
	int i=10;
	void *virtual_addr = (void *)&i;
	phys_addr_t physical_addr = virt_to_phys(virtual_addr);

	pr_info("Virtual Address of i is %px\n", virtual_addr);
	pr_info("physical Address of i is %pa\n", &physical_addr);
	pr_info("Virtual Address of i is %px\n", phys_to_virt(physical_addr));

	return -1;
}

static void __exit hello_exit(void){
}

module_init(hello_init);
module_exit(hello_exit);


