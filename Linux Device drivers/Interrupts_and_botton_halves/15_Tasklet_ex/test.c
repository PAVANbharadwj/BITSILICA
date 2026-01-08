#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");

static char tasklet_data[] = "linux kernel is very easy";

static void tasklet_function(struct tasklet_struct *t)
{
    pr_info("%s: data: %s\n", __func__, tasklet_data);
}


DECLARE_TASKLET(my_tasklet, tasklet_function);
DECLARE_TASKLET_DISABLED(my_tasklet_disabled, tasklet_function);

static int __init test_tasklet_init(void)
{
    pr_info("%s: In init\n", __func__);

    pr_info("State: %lu\n", my_tasklet.state);
    pr_info("Count: %d\n", atomic_read(&my_tasklet.count));
    pr_info("State(disabled): %lu\n", my_tasklet_disabled.state);
    pr_info("Count(disabled): %d\n",atomic_read(&my_tasklet_disabled.count));


    tasklet_schedule(&my_tasklet);

    return 0;
}

static void __exit test_tasklet_exit(void)
{
    tasklet_kill(&my_tasklet);
    tasklet_kill(&my_tasklet_disabled);

    pr_info("%s: In exit\n", __func__);
}

module_init(test_tasklet_init);
module_exit(test_tasklet_exit);

