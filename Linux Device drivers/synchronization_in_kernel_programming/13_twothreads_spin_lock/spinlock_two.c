#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/sched.h>
#include <linux/spinlock.h>

MODULE_LICENSE("GPL");


unsigned int counter;


DEFINE_SPINLOCK(counter_lock);


static struct task_struct *read_thread, *write_thread;

static int writer_function(void *data)
{
    while (!kthread_should_stop()) {
        spin_lock(&counter_lock);
        counter++;
        spin_unlock(&counter_lock);
        msleep(500);
    }
   return 0; 
}

static int read_function(void *data)
{
    while (!kthread_should_stop()) {
        spin_lock(&counter_lock);
        pr_info("counter: %d\n", counter);
        spin_unlock(&counter_lock);
        msleep(500);
    }
    return 0;
}

static int __init test_hello_init(void)
{
    pr_info("%s: In init\n", __func__);


    write_thread = kthread_run(writer_function, NULL, "writer_thread");
    if (!write_thread) {
        pr_err("Failed to create writer thread\n");
        return -1;
    }

    read_thread = kthread_run(read_function, NULL, "read_thread");
    if (!read_thread) {
        pr_err("Failed to create read thread\n");
        kthread_stop(write_thread);
        return -1;
    }

    return 0;
}

static void __exit test_hello_exit(void)
{
    pr_info("%s: In exit\n", __func__);

    if (write_thread)
        kthread_stop(write_thread);
    if (read_thread)
        kthread_stop(read_thread);

    pr_info("Threads stopped. Final counter value: %d\n", counter);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

