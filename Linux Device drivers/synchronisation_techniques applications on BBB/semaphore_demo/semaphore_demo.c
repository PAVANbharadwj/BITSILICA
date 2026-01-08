#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/semaphore.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavan");
MODULE_DESCRIPTION("Semaphore demo with limited shared resource");

#define MAX_USERS 2
#define NUM_THREADS 3


struct shared_resource {
    int active_users;
    int total_access;
};

static struct shared_resource resource;


static struct semaphore sem;


static struct task_struct *threads[NUM_THREADS];


static int worker_fn(void *data)
{
    int id = (int)(long)data;

    while (!kthread_should_stop()) {

        pr_info("Thread-%d: waiting for semaphore\n", id);


        down(&sem);


        resource.active_users++;
        resource.total_access++;

        pr_info("Thread-%d ENTERED | active=%d total=%d\n",
                id, resource.active_users, resource.total_access);


        msleep(2000);

        resource.active_users--;

        pr_info("Thread-%d EXITING | active=%d\n",
                id, resource.active_users);


        up(&sem);

        msleep(1000);
    }

    return 0;
}

static int __init semaphore_demo_init(void)
{
    int i;

    pr_info("semaphore_demo: module loaded\n");


    sema_init(&sem, MAX_USERS);

    resource.active_users = 0;
    resource.total_access = 0;


    for (i = 0; i < NUM_THREADS; i++) {
        threads[i] = kthread_run(worker_fn,
                                 (void *)(long)(i + 1),
                                 "sem_thread_%d", i + 1);
    }

    return 0;
}

static void __exit semaphore_demo_exit(void)
{
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        if (threads[i])
            kthread_stop(threads[i]);
    }

    pr_info("semaphore_demo: final total_access=%d\n",
            resource.total_access);

    pr_info("semaphore_demo: module unloaded\n");
}

module_init(semaphore_demo_init);
module_exit(semaphore_demo_exit);

