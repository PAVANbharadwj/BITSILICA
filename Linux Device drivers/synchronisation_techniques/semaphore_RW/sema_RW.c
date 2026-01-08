#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/rwsem.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavan");
MODULE_DESCRIPTION("Read-Write Semaphore demo (sleeping readers/writer)");

#define NUM_READERS 3

struct shared_db {
    int value;
    int version;
};

static struct shared_db database;


static struct rw_semaphore db_sem;


static struct task_struct *reader_threads[NUM_READERS];
static struct task_struct *writer_thread;


static int reader_fn(void *data)
{
    int id = (int)(long)data;

    while (!kthread_should_stop()) {


        down_read(&db_sem);

        pr_info("Reader-%d: value=%d version=%d\n",
                id, database.value, database.version);


        msleep(1000);

        up_read(&db_sem);

        msleep(500);
    }

    return 0;
}

static int writer_fn(void *data)
{
  while (!kthread_should_stop()) {


        down_write(&db_sem);

        database.value += 100;
        database.version++;

        pr_info("WRITER: updated value=%d version=%d\n",
                database.value, database.version);


        msleep(2000);

        up_write(&db_sem);

        msleep(3000);
    }

    return 0;
}

static int __init rwsem_demo_init(void)
{
    int i;

    pr_info("rwsem_demo: module loaded\n");

    init_rwsem(&db_sem);

    database.value = 0;
    database.version = 0;


    for (i = 0; i < NUM_READERS; i++) {
        reader_threads[i] = kthread_run(reader_fn,
                                        (void *)(long)(i + 1),
                                        "rwsem_reader_%d", i + 1);
    }


    writer_thread = kthread_run(writer_fn, NULL, "rwsem_writer");

    return 0;
}

static void __exit rwsem_demo_exit(void)
{
    int i;

    if (writer_thread)
        kthread_stop(writer_thread);

    for (i = 0; i < NUM_READERS; i++) {
        if (reader_threads[i])
            kthread_stop(reader_threads[i]);
    }

    pr_info("rwsem_demo: module unloaded\n");
}

module_init(rwsem_demo_init);
module_exit(rwsem_demo_exit);

