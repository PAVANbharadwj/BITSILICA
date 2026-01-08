#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <asm/pgtable.h>

MODULE_LICENSE("GPL");

static int test_hello_init(void)
{
    pr_info("Vmalloc start : 0x%lx\n", (unsigned long)VMALLOC_START);
    pr_info("Vmalloc end   : 0x%lx\n", (unsigned long)VMALLOC_END);
    pr_info("Vmalloc size  : %lu MB\n",
            (unsigned long)((VMALLOC_END - VMALLOC_START) / (1024 * 1024)));

    return 0;
}

static void test_hello_exit(void)
{
    pr_info("Module unloaded\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);

