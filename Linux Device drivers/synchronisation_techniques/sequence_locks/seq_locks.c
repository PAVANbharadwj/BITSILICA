#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/seqlock.h>
#include <linux/delay.h>
#include <linux/jiffies.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavan");
MODULE_DESCRIPTION("Seqlock demo - read mostly data");

#define NUM_READERS 3


struct stats {
    int temperature;
    int voltage;
    unsigned long timestamp;
};

static struct stats sys_stats;


static seqlock_t stats_lock;


static struct task_struct *reader_threads[NUM_READERS];
static struct task_struct *writer_thread;


static int reader_fn(void *data)
{
    int id = (int)(long)data;
    unsigned seq;
    struct stats local;

    while (!kthread_should_stop()) {

        do {

            seq = read_seqbegin(&stats_lock);


            local.temperature = sys_stats.temperature;
            local.voltage = sys_stats.voltage;
            local.timestamp = sys_stats.timestamp;


        } while (read_seqretry(&stats_lock, seq));

        pr_info("Reader-%d: temp=%d volt=%d time=%lu\n",
                id, local.temperature, local.voltage, local.timestamp);

        msleep(500);
    }

    return 0;
}


static int writer_fn(void *data)
{
    while (!kthread_should_stop()) {

        write_seqlock(&stats_lock);

        sys_stats.temperature += 1;
        sys_stats.voltage += 5;
        sys_stats.timestamp = jiffies;

        write_sequnlock(&stats_lock);

        msleep(2000);
    }

    return 0;
}

static int __init seqlock_demo_init(void)
{
    int i;

    pr_info("seqlock_demo: module loaded\n");

    seqlock_init(&stats_lock);

    sys_stats.temperature = 25;
    sys_stats.voltage = 3300;
    sys_stats.timestamp = jiffies;


    for (i = 0; i < NUM_READERS; i++) {
        reader_threads[i] = kthread_run(reader_fn,
                                        (void *)(long)(i + 1),
                                        "seqlock_reader_%d", i + 1);
    }


    writer_thread = kthread_run(writer_fn, NULL, "seqlock_writer");

    return 0;
}

static void __exit seqlock_demo_exit(void)
{
    int i;

    if (writer_thread)
        kthread_stop(writer_thread);

    for (i = 0; i < NUM_READERS; i++) {
        if (reader_threads[i])
            kthread_stop(reader_threads[i]);
    }

    pr_info("seqlock_demo: module unloaded\n");
}

module_init(seqlock_demo_init);
module_exit(seqlock_demo_exit);

