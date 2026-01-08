#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/atomic.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/timer.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavan");
MODULE_DESCRIPTION("Atomic variable demo on BBB");

static atomic_t shared_counter = ATOMIC_INIT(0);

static struct task_struct *thread;
static struct timer_list my_timer;


static int thread_fn(void *data)
{
    while (!kthread_should_stop()) {
        atomic_inc(&shared_counter);
        pr_info("Thread incremented counter: %d\n",
                atomic_read(&shared_counter));
        msleep(1000);
    }
    return 0;
}


static void timer_callback(struct timer_list *t)
{
    atomic_inc(&shared_counter);
    pr_info("Timer incremented counter: %d\n",
            atomic_read(&shared_counter));

    mod_timer(&my_timer, jiffies + msecs_to_jiffies(2000));
}

static int __init atomic_demo_init(void)
{
    pr_info("atomic_demo: module loaded\n");


    thread = kthread_run(thread_fn, NULL, "atomic_thread");


    timer_setup(&my_timer, timer_callback, 0);
    mod_timer(&my_timer, jiffies + msecs_to_jiffies(2000));

    return 0;
}

static void __exit atomic_demo_exit(void)
{
    del_timer_sync(&my_timer);

    if (thread)
        kthread_stop(thread);

    pr_info("atomic_demo: final counter value = %d\n",
            atomic_read(&shared_counter));
    pr_info("atomic_demo: module unloaded\n");
}

module_init(atomic_demo_init);
module_exit(atomic_demo_exit);

