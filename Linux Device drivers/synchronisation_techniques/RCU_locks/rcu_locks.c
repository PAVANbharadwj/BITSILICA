#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/rcupdate.h>
#include <linux/slab.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavan");
MODULE_DESCRIPTION("RCU demo - lockless readers, safe writers");

#define NUM_READERS 3


struct config {
    int param1;
    int param2;
};


static struct config __rcu *rcu_cfg;


static struct task_struct *reader_threads[NUM_READERS];
static struct task_struct *writer_thread;


static int reader_fn(void *data)
{
    int id = (int)(long)data;
    struct config *cfg;

    while (!kthread_should_stop()) {

        rcu_read_lock();

        cfg = rcu_dereference(rcu_cfg);
        if (cfg)
            pr_info("Reader-%d: param1=%d param2=%d\n",
                    id, cfg->param1, cfg->param2);

        rcu_read_unlock();

        msleep(500);
    }

    return 0;
}


static int writer_fn(void *data)
{
    struct config *new_cfg, *old_cfg;

    while (!kthread_should_stop()) {


        new_cfg = kmalloc(sizeof(*new_cfg), GFP_KERNEL);
        if (!new_cfg)
            continue;

        new_cfg->param1 = jiffies % 100;
        new_cfg->param2 = (jiffies / 10) % 100;


        old_cfg = rcu_replace_pointer(rcu_cfg, new_cfg, true);

        pr_info("WRITER: updated config p1=%d p2=%d\n",
                new_cfg->param1, new_cfg->param2);


        synchronize_rcu();


        if (old_cfg)
            kfree(old_cfg);

        msleep(3000);
    }

    return 0;
}

static int __init rcu_demo_init(void)
{
    int i;
    struct config *init_cfg;

    pr_info("rcu_demo: module loaded\n");


    init_cfg = kmalloc(sizeof(*init_cfg), GFP_KERNEL);
    if (!init_cfg)
        return -ENOMEM;

    init_cfg->param1 = 10;
    init_cfg->param2 = 20;

    rcu_assign_pointer(rcu_cfg, init_cfg);


    for (i = 0; i < NUM_READERS; i++) {
        reader_threads[i] = kthread_run(reader_fn,
                                        (void *)(long)(i + 1),
                                        "rcu_reader_%d", i + 1);
    }


    writer_thread = kthread_run(writer_fn, NULL, "rcu_writer");

    return 0;
}

static void __exit rcu_demo_exit(void)
{
    int i;
    struct config *cfg;

    if (writer_thread)
        kthread_stop(writer_thread);

    for (i = 0; i < NUM_READERS; i++) {
        if (reader_threads[i])
            kthread_stop(reader_threads[i]);
    }


    cfg = rcu_dereference_protected(rcu_cfg, true);
    if (cfg)
        kfree(cfg);

    pr_info("rcu_demo: module unloaded\n");
}

module_init(rcu_demo_init);
module_exit(rcu_demo_exit);

