#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/semaphore.h>

MODULE_LICENSE("GPL");

struct semaphore mysem;

static int __init test_hello_init(void)
{
    int ret;

 
    sema_init(&mysem, 1);
    pr_info("%s: mysem.count: 0x%x\n", __func__, mysem.count);

 
    down(&mysem);
    pr_info("%s: mysem.count after down: 0x%x\n", __func__, mysem.count);

  
    ret = down_trylock(&mysem);
    pr_info("%s: mysem.count after down_trylock: 0x%x\t ret=%d\n",
            __func__, mysem.count, ret);

    return -1; 
}

static void __exit test_hello_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

