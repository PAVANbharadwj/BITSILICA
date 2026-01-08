#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/seqlock.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/smp.h>

MODULE_LICENSE("GPL");

static seqlock_t mylock;
static struct task_struct *thread1, *thread2;
static int counter = 0;

static int write_threadfn(void *arg)
{
    while (!kthread_should_stop()) {
        pr_info("processor:%d trying to acquire write seq lock\n",
                smp_processor_id());
        write_seqlock(&mylock);
        pr_info("processor:%d acquired write seq lock\n",
                smp_processor_id());

        counter++;

        mdelay(7000);

        write_sequnlock(&mylock);
        pr_info("processor:%d released write seq lock\n",
                smp_processor_id());

        mdelay(2000);
    }
    return 0;
}

static int read_threadfn(void *arg)
{
    unsigned int seq;
    int mycounter;

    while (!kthread_should_stop()) {
        pr_info("processor:%d starting seqread\n", smp_processor_id());

        do {
            seq = read_seqbegin(&mylock);
            mycounter = counter;
            pr_info("processor:%d read_seq read mycounter:%d\n",
                    smp_processor_id(), mycounter);

        } while (read_seqretry(&mylock, seq));

        pr_info("processor:%d completed seqread\n",
                smp_processor_id());
        pr_info("processor:%d counter:%d\n",
                smp_processor_id(), mycounter);

        mdelay(2000);
    }
    return 0;
}

static int __init test_hello_init(void)
{
    seqlock_init(&mylock);

    thread1 = kthread_run(read_threadfn, NULL, "reader_thread");
    thread2 = kthread_run(write_threadfn, NULL, "writer_thread");

    return 0;
}

static void __exit test_hello_exit(void)
{
    kthread_stop(thread1);
    kthread_stop(thread2);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

