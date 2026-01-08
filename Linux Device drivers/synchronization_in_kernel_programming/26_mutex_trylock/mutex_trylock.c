#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/mutex.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/smp.h>

MODULE_LICENSE("GPL");


DEFINE_MUTEX(mylock);

static struct task_struct *thread1, *thread2;

static int threadfn(void *arg)
{
    int ret;

    while (!kthread_should_stop()) {


        ret = mutex_trylock(&mylock);

        pr_info("%s: Starting critical region on CPU:%d ret=%d\n",
                __func__, smp_processor_id(), ret);

        if (!ret) {

           pr_info("%s: Holding mutex - sleeping 2s\n", __func__);

            msleep(2000);

            pr_info("%s: Ending critical region, unlocking mutex\n", __func__);

            mutex_unlock(&mylock);
        } else {

           pr_info("%s: Could not acquire mutex, skipping critical region\n",
                    __func__);
        }

        msleep(1000); 
    }
    return 0;
}



static int __init test_hello_init(void)
{
    pr_info("%s: Module loaded, starting threads\n", __func__);


    thread1 = kthread_run(threadfn, NULL, "thread1");
    thread2 = kthread_run(threadfn, NULL, "thread2");

    return 0;
}

static void __exit test_hello_exit(void)
{
    pr_info("%s: Stopping threads\n", __func__);
    kthread_stop(thread1);
    kthread_stop(thread2);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

