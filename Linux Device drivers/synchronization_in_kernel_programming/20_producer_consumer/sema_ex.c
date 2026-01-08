#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/semaphore.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/smp.h>

MODULE_LICENSE("GPL");

struct semaphore *mysem;
static struct task_struct *thread1, *thread2;
static char buffer[10];


static int producer(void *arg)
{
    char ch = 'A';

    while (!kthread_should_stop()) {

        pr_info("%s: trying to acquire semaphore on processor:%d\n",
                __func__, smp_processor_id());

        down(mysem);

        pr_info("%s: acquired semaphore on processor:%d\n",
                __func__, smp_processor_id());

        memset(buffer, ch, sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';

        pr_info("%s: Produced Data: %s\n", __func__, buffer);

        msleep(2000);

        pr_info("%s: releasing semaphore on processor:%d\n",
                __func__, smp_processor_id());

        up(mysem); 
    }

    return 0;
}


static int consumer(void *arg)
{
    while (!kthread_should_stop()) {

        pr_info("%s: trying to acquire semaphore on processor:%d\n",
                __func__, smp_processor_id());

        down(mysem); 
        pr_info("%s: acquired semaphore on processor:%d\n",
                __func__, smp_processor_id());
        pr_info("%s: Consumed Data: %s\n",
                __func__, buffer);

        memset(buffer, 0, sizeof(buffer));
        pr_info("%s: Cleared Data\n", __func__);

        msleep(2000);

        pr_info("%s: releasing semaphore on processor:%d\n",
                __func__, smp_processor_id());

        up(mysem); 
    }
    return 0;
}


static int __init test_hello_init(void)
{
    mysem = kmalloc(sizeof(struct semaphore), GFP_KERNEL);

    memset(buffer, 0, sizeof(buffer));

    sema_init(mysem, 1); 

    thread1 = kthread_run(producer, NULL, "thread1");
    thread2 = kthread_run(consumer, NULL, "thread2");

    return 0;
}

static void __exit test_hello_exit(void)
{
    kthread_stop(thread1);
    kthread_stop(thread2);

    kfree(mysem);
    pr_info("%s: exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

