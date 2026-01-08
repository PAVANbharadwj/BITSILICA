#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/mutex.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");


DEFINE_MUTEX(mylock);

static int __init test_hello_init(void)
{
    pr_info("%s: Module init\n", __func__);

    pr_info("%s: Trying to acquire mutex\n", __func__);
    mutex_lock(&mylock); 

    pr_info("%s: Mutex acquired, entering critical region\n", __func__);


    pr_info("%s: Sleeping for 2 seconds inside mutex...\n", __func__);
    msleep(2000);

    pr_info("%s: Woke up, still inside critical region\n", __func__);

    mutex_unlock(&mylock);
    pr_info("%s: Released mutex, leaving critical region\n", __func__);

    return -1;   
}

static void __exit test_hello_exit(void)
{
    pr_info("%s: Module exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

