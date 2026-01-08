#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

static char tasklet_data[] = "linux kernel is very easy";

static struct tasklet_struct *my_tasklet;

static void tasklet_function(unsigned long data)
{
    pr_info("%s: data: %s\n", __func__, (char*)data);
}

static int __init test_tasklet_init(void)
{
    pr_info("%s: In init\n", __func__);

    my_tasklet = kmalloc(sizeof(*my_tasklet), GFP_KERNEL);
    if (!my_tasklet)
        return -ENOMEM;

    tasklet_init(my_tasklet, tasklet_function,(unsigned long)tasklet_data);

    pr_info("State(after init): %lu\n", my_tasklet->state);
    pr_info("Count(after init): %d\n",
            atomic_read(&my_tasklet->count));

    tasklet_schedule(my_tasklet);
    return 0;
}

static void __exit test_tasklet_exit(void)
{
    tasklet_kill(my_tasklet);
    kfree(my_tasklet);

    pr_info("%s: In exit\n", __func__);
}

module_init(test_tasklet_init);
module_exit(test_tasklet_exit);

