#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/seqlock.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

seqlock_t *seqlock;

static int __init test_hello_init(void)
{
    seqlock = kmalloc(sizeof(seqlock_t), GFP_KERNEL);
    seqlock_init(seqlock);

    pr_info("init seqcount:%u\n",
            seqlock->seqcount.seqcount.sequence);

    write_seqlock(seqlock);
    pr_info("after write_seqlock seqcount:%u\n",
            seqlock->seqcount.seqcount.sequence);
    write_sequnlock(seqlock);
    pr_info("after write_sequnlock seqcount:%u\n",
            seqlock->seqcount.seqcount.sequence);

    write_seqlock(seqlock);
    pr_info("after write_seqlock seqcount:%u\n",
            seqlock->seqcount.seqcount.sequence);
    write_sequnlock(seqlock);
    pr_info("after write_sequnlock seqcount:%u\n",
            seqlock->seqcount.seqcount.sequence);

    kfree(seqlock);
    return -1;
}

static void __exit test_hello_exit(void)
{
    pr_info("%s exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

