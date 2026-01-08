#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/delay.h>

static struct task_struct *my_thread;

static int thread_fn(void *arg)
{
    int count = 0;

    pr_info("kthread: started\n");

    while (!kthread_should_stop()) {
        pr_info("kthread: running %d\n", count++);
        msleep(1000);   // sleep for 1 second
    }

    pr_info("kthread: stopping\n");
    return 0;
}

static int __init my_kthread_init(void)
{
    pr_info("module loaded\n");

    /* Create thread but it will not run until we wake it */
    my_thread = kthread_create(thread_fn, NULL, "my_kthread");

    /* Start executing the thread */
    wake_up_process(my_thread);

    return 0;
}

static void __exit my_kthread_exit(void)
{
    pr_info("module unloading\n");

    /* Stop the thread */
    if (my_thread)
        kthread_stop(my_thread);
}

module_init(my_kthread_init);
module_exit(my_kthread_exit);

MODULE_LICENSE("GPL");

