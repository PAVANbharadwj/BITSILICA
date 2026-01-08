#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/smp.h>

static struct task_struct *my_thread;

int thread_function(void *pv)
{
    int i = 0;
    while (!kthread_should_stop()) {
        printk(KERN_INFO "Processor id:%d\t In Thread Function %d\n", smp_processor_id(), i++);
        msleep(1000);
    }
    return 0;
}

static int __init my_driver_init(void)
{
    pr_info("%s: processor id:%d\n", __func__, smp_processor_id());
    my_thread = kthread_create(thread_function, NULL, "myThread");

    if (my_thread) {
        wake_up_process(my_thread);
        return 0;
    } else {
        printk(KERN_ERR "Cannot create kthread\n");
        return -1;
    }
}

static void __exit my_driver_exit(void)
{
    kthread_stop(my_thread);
    pr_info("%s: Device Driver Remove...Done\tProcessor Id:%d\n",
            __func__, smp_processor_id());
}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_LICENSE("GPL");

