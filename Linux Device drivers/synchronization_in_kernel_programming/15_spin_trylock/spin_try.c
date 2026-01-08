#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/spinlock.h>

MODULE_LICENSE("GPL");

static DEFINE_SPINLOCK(my_lock);
static int data = 10;

static int __init simple_init(void)
{
    pr_info("Module loaded\n");

    /* First try: lock is free → should succeed */
    if (spin_trylock(&my_lock)) {
        pr_info("Lock acquired, data=%d\n", data);
        data++;
        pr_info("Updated data=%d\n", data);
        spin_unlock(&my_lock);
    } else {
        pr_info("Could not acquire lock (1st try)\n");
    }

    /* Second try: we hold lock manually → trylock should fail */
    spin_lock(&my_lock);
    pr_info("Manually locked – now testing trylock again...\n");

    if (spin_trylock(&my_lock)) {
        pr_info("Unexpected: lock acquired again!\n");
        spin_unlock(&my_lock);
    } else {
        pr_info("Expected: spin_trylock() could NOT acquire lock\n");
    }

    /* release what we manually locked */
    spin_unlock(&my_lock);

    return -1;   /* unload automatically */
}

static void __exit simple_exit(void)
{
    pr_info("Module unloaded\n");
}

module_init(simple_init);
module_exit(simple_exit);

