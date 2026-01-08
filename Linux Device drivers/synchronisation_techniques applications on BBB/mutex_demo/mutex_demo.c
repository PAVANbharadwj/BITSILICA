#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/semaphore.h>
#include <linux/mutex.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavan");
MODULE_DESCRIPTION("Producer Consumer using semaphore and mutex");

#define BUFFER_SIZE 5


static int buffer[BUFFER_SIZE];
static int in = 0;
static int out = 0;


static struct semaphore sem_empty;
static struct semaphore sem_full;
static struct mutex buffer_mutex;


static struct task_struct *producer_thread;
static struct task_struct *consumer_thread;


static int producer_fn(void *data)
{
    int item = 0;

    while (!kthread_should_stop()) {


        down(&sem_empty);


        mutex_lock(&buffer_mutex);


        buffer[in] = item;
        pr_info("Producer produced: %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        item++;

        mutex_unlock(&buffer_mutex);


        up(&sem_full);

        msleep(1000);
    }

    return 0;
}


static int consumer_fn(void *data)
{
    int item;

    while (!kthread_should_stop()) {


        down(&sem_full);


        mutex_lock(&buffer_mutex);


        item = buffer[out];
        pr_info("Consumer consumed: %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        mutex_unlock(&buffer_mutex);


        up(&sem_empty);

        msleep(1500);
    }

    return 0;
}

static int __init pc_init(void)
{
    pr_info("Producer-Consumer module loaded\n");


    sema_init(&sem_empty, BUFFER_SIZE);
    sema_init(&sem_full, 0);


    mutex_init(&buffer_mutex);


    producer_thread = kthread_run(producer_fn, NULL, "producer_thread");
    consumer_thread = kthread_run(consumer_fn, NULL, "consumer_thread");

    return 0;
}

static void __exit pc_exit(void)
{
    if (producer_thread)
        kthread_stop(producer_thread);

    if (consumer_thread)
        kthread_stop(consumer_thread);

    pr_info("Producer-Consumer module unloaded\n");
}

module_init(pc_init);
module_exit(pc_exit);

