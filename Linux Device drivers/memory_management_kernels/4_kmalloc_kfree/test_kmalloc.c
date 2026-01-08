#include<linux/moduleparam.h>
#include<linux/slab.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<asm/io.h>


MODULE_LICENSE("GPL");


static void *ptr;
int alloc_size = 1024;

module_param(alloc_size,int,0);

static int __init hello_init(void)
{
	pr_info("Module loaded\n");
	ptr = kmalloc(alloc_size,GFP_ATOMIC);
	if(!ptr){
		pr_err("memory allocation failed");
		return -ENOMEM;
	}
	else{
		phys_addr_t physical_addr = virt_to_phys(ptr);
		pr_info("Memory allocated:%px\n",ptr);
		pr_info("Physical Address is %pa\n",&physical_addr);
	}
	return 0;
}

static void __exit hello_exit(void)
{
	if(ptr){
		kfree(ptr);
		pr_info("Memory freed\n");
	}

	pr_info("Module unloaded\n");
}
module_init(hello_init);
module_exit(hello_exit);





