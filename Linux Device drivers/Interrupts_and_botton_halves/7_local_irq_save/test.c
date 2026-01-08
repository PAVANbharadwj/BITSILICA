#include <linux/module.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/irqflags.h>

static int __init my_init(void)
{
    pr_info("module is loaded on processor:%d\n", smp_processor_id());
    unsigned long flags;
    local_irq_save(flags);
    pr_info("flags:%02lx\n", flags);

    ssleep(10);

    local_irq_restore(flags);
    return 0;
}

static void __exit my_exit(void)
{
}

MODULE_LICENSE("GPL");
module_init(my_init);
module_exit(my_exit);

