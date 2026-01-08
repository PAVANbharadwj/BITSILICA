#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/delay.h>

static struct task_struct *thread1;
static struct task_struct *thread2;

static int thread_fn1(void *arg)
{
    int i = 0;
    while (!kthread_should_stop()) {
        pr_info("Thread 1 running: %d\n", i++);
        msleep(1000);          // sleep 1 sec
    }
    pr_info("Thread 1 stopped\n");
    return 0;
}

static int thread_fn2(void *arg)
{
    int i = 0;
    while (!kthread_should_stop()) {
        pr_info("Thread 2 running: %d\n", i++);
        msleep(1500);          // sleep 1.5 sec
    }
    pr_info("Thread 2 stopped\n");
    return 0;
}

static int __init my_init(void)
{
    pr_info("Module loaded, creating threads...\n");

    thread1 = kthread_run(thread_fn1, NULL, "my_thread1");
    thread2 = kthread_run(thread_fn2, NULL, "my_thread2");

    return 0;
}

static void __exit my_exit(void)
{
    pr_info("Stopping threads...\n");

    if (thread1)
        kthread_stop(thread1);

    if (thread2)
        kthread_stop(thread2);

    pr_info("Module unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");

