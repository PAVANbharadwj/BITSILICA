#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/rwsem.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

struct rw_semaphore *mysem;

static int __init test_hello_init(void)
{
    mysem = kmalloc(sizeof(struct rw_semaphore), GFP_KERNEL);
    init_rwsem(mysem);

    pr_info("count:%ld\n", atomic_long_read(&mysem->count));

    kfree(mysem);
    return -1;
}

static void __exit test_hello_exit(void)
{
    pr_info("%s: exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

