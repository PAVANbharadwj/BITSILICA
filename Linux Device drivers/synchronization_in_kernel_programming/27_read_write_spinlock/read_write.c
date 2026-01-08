#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/spinlock.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/smp.h>

MODULE_LICENSE("GPL");

static rwlock_t mylock;
static struct task_struct *thread1, *thread2, *thread3;
static int counter = 0;

static int read_threadfn(void *arg)
{
    while (!kthread_should_stop()) {
        pr_info("processor:%d trying to acquire read lock\n", smp_processor_id());
        read_lock(&mylock);
        pr_info("processor:%d acquired read lock\n", smp_processor_id());
        pr_info("processor:%d counter:%d\n", smp_processor_id(), counter);
        mdelay(5000);
        read_unlock(&mylock);
        pr_info("processor:%d releasing read lock\n", smp_processor_id());
        mdelay(1000);
    }
    return 0;
}

static int write_threadfn(void *arg)
{
    while (!kthread_should_stop()) {
        pr_info("processor:%d trying to acquire write lock\n", smp_processor_id());
        write_lock(&mylock);
        pr_info("processor:%d acquired write lock\n", smp_processor_id());
        counter++;
        pr_info("processor:%d updated counter:%d\n", smp_processor_id(), counter);
        mdelay(3000);
        write_unlock(&mylock);
        pr_info("processor:%d releasing write lock\n", smp_processor_id());
        mdelay(2000);
    }
    return 0;
}

static int __init test_hello_init(void)
{
    rwlock_init(&mylock);
    thread1 = kthread_run(read_threadfn, NULL, "thread1");
    thread2 = kthread_run(read_threadfn, NULL, "thread2");
    thread3 = kthread_run(write_threadfn, NULL, "thread3");
    return 0;
}

static void __exit test_hello_exit(void)
{
    kthread_stop(thread1);
    kthread_stop(thread2);
    kthread_stop(thread3);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

