#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/semaphore.h>

MODULE_LICENSE("GPL");

static struct semaphore mysem;

static int __init test_hello_init(void)
{
 
    sema_init(&mysem, 2);

    pr_info("%s: Initial mysem.count: 0x%x\n", __func__, mysem.count);

    down(&mysem);
    pr_info("%s: After down(): mysem.count: 0x%x\n", __func__, mysem.count);




    up(&mysem);
    pr_info("%s: After up(): mysem.count: 0x%x\n", __func__, mysem.count);

    down(&mysem);
    pr_info("%s: After down(): mysem.count: 0x%x\n", __func__, mysem.count);

    return -1;
}

static void __exit test_hello_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

