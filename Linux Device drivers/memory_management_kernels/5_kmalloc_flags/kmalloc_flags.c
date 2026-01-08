#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>
#include<asm/io.h>

MODULE_LICENSE("GPL");

static void *ptr;
int alloc_size = 1024;

static int test_hello_init(void)
{
    phys_addr_t physical_address;

    ptr = kmalloc(alloc_size, GFP_DMA);
    pr_info("Virtual Address:%px\n", ptr);
    physical_address = virt_to_phys(ptr);
    pr_info("Physical Address:%pa\n", &physical_address);
    kfree(ptr);

    ptr = kmalloc(alloc_size, GFP_DMA32);
    pr_info("Virtual Address:%px\n", ptr);
    physical_address = virt_to_phys(ptr);
    pr_info("Physical Address:%pa\n", &physical_address);
    kfree(ptr);

    return 0;
}

static void test_hello_exit(void)
{
    pr_info("Module unloaded\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);

