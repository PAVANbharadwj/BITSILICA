#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/spinlock.h>
#include <linux/kthread.h>
#include <linux/timer.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavan");
MODULE_DESCRIPTION("Spinlock demo with thread and timer");

/* Shared data */
struct shared_data {
    int counter;
    int last_writer; /* 1 = thread, 2 = timer */
};

static struct shared_data data;

/* Spinlock */
static spinlock_t lock;

/* Kernel thread and timer */
static struct task_struct *worker;
static struct timer_list my_timer;

/* Kernel thread function */
static int thread_fn(void *arg)
{
    unsigned long flags;

    while (!kthread_should_stop()) {

        spin_lock_irqsave(&lock, flags);

        data.counter++;
        data.last_writer = 1;

        pr_info("Thread: counter=%d last_writer=%d\n",
                data.counter, data.last_writer);

        spin_unlock_irqrestore(&lock, flags);

        msleep(1000);
    }

    return 0;
}

/* Timer callback (interrupt context) */
static void timer_callback(struct timer_list *t)
{
    unsigned long flags;

    spin_lock_irqsave(&lock, flags);

    data.counter++;
    data.last_writer = 2;

    pr_info("Timer : counter=%d last_writer=%d\n",
            data.counter, data.last_writer);

    spin_unlock_irqrestore(&lock, flags);

    mod_timer(&my_timer, jiffies + msecs_to_jiffies(2000));
}

static int __init spinlock_demo_init(void)
{
    pr_info("spinlock_demo: module loaded\n");

    spin_lock_init(&lock);

    data.counter = 0;
    data.last_writer = 0;

    worker = kthread_run(thread_fn, NULL, "spinlock_thread");

    timer_setup(&my_timer, timer_callback, 0);
    mod_timer(&my_timer, jiffies + msecs_to_jiffies(2000));

    return 0;
}

static void __exit spinlock_demo_exit(void)
{
    del_timer_sync(&my_timer);

    if (worker)
        kthread_stop(worker);

    pr_info("spinlock_demo: final counter=%d\n", data.counter);
    pr_info("spinlock_demo: module unloaded\n");
}

module_init(spinlock_demo_init);
module_exit(spinlock_demo_exit);

