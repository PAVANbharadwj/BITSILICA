#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/spinlock.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavan");
MODULE_DESCRIPTION("Read Write Lock demo - multiple readers, single writer");

#define NUM_READERS 3


struct shared_state {
    int value;
    int version;
};

static struct shared_state state;


static rwlock_t state_lock;


static struct task_struct *reader_threads[NUM_READERS];
static struct task_struct *writer_thread;


static int reader_fn(void *data)
{
    int id = (int)(long)data;

    while (!kthread_should_stop()) {

        read_lock(&state_lock);

        pr_info("Reader-%d: value=%d version=%d\n",
                id, state.value, state.version);

        read_unlock(&state_lock);

        msleep(500);
    }

    return 0;
}


static int writer_fn(void *data)
{
    while (!kthread_should_stop()) {

        write_lock(&state_lock);

        state.value += 10;
        state.version++;

        pr_info("WRITER: updated value=%d version=%d\n",
                state.value, state.version);

        write_unlock(&state_lock);

        msleep(2000);
    }

    return 0;
}

static int __init rwlock_demo_init(void)
{
    int i;

    pr_info("rwlock_demo: module loaded\n");

    rwlock_init(&state_lock);

    state.value = 0;
    state.version = 0;


    for (i = 0; i < NUM_READERS; i++) {
        reader_threads[i] = kthread_run(reader_fn,
                                        (void *)(long)(i + 1),
                                        "reader_%d", i + 1);
    }


    writer_thread = kthread_run(writer_fn, NULL, "writer");

    return 0;
}

static void __exit rwlock_demo_exit(void)
{
    int i;

    if (writer_thread)
        kthread_stop(writer_thread);

    for (i = 0; i < NUM_READERS; i++) {
        if (reader_threads[i])
            kthread_stop(reader_threads[i]);
    }

    pr_info("rwlock_demo: module unloaded\n");
}

module_init(rwlock_demo_init);
module_exit(rwlock_demo_exit);

