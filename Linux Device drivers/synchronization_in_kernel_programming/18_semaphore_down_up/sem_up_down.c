#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/semaphore.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

struct semaphore *mysem;

static int __init test_hello_init(void)
{
 
    mysem = kmalloc(sizeof(struct semaphore), GFP_KERNEL);


    sema_init(mysem, 1);
    pr_info("semaphore count:%d\n",mysem->count);

    down(mysem); 
    pr_info("semaphore count:%d\n",mysem->count);
    pr_info("Starting critical region\n");
    pr_info("Ending critical region\n");
    up(mysem);   
    pr_info("semaphore count:%d\n",mysem->count);
    kfree(mysem);
    return -1;   
}

static void __exit test_hello_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

