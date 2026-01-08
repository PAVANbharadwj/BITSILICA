#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>
#include <linux/io.h>

MODULE_LICENSE("GPL");

static char *ptr;
int alloc_size = 1024;

module_param(alloc_size, int, 0);

static int test_hello_init(void)
{
    phys_addr_t phys_base, phys_offset;

    ptr = kmalloc(alloc_size, GFP_ATOMIC);
    if (!ptr) {
        pr_err("memory allocation failed\n");
        return -ENOMEM;
    }

    phys_base   = virt_to_phys(ptr);
    phys_offset = virt_to_phys(ptr + 100);

    pr_info("Memory allocated successfully\n");
    pr_info("Virtual base address      : %px\n", ptr);
    pr_info("Virtual address (ptr+100): %px\n", ptr + 100);

    pr_info("Physical base address      : %pa\n", &phys_base);
    pr_info("Physical address (ptr+100): %pa\n", &phys_offset);

    kfree(ptr);
    return 0;
}

static void test_hello_exit(void)
{
    pr_info("Module unloaded\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);

