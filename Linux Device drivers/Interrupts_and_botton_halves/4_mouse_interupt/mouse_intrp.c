#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");

#define SHARED_IRQ 12 

static int irq = SHARED_IRQ;
static int my_dev_id;
static int irq_counter=0;

module_param(irq, int, S_IRUGO);

static irqreturn_t my_mouse_interrupt(int irq, void *dev_id)
{
    irq_counter++;
    pr_info("Mouse ISR: counter = %d\n", irq_counter);

    return IRQ_NONE;
}

static int __init my_init(void)
{
    if (request_irq(irq,
                    my_mouse_interrupt,
                    IRQF_SHARED,
                    "my_mouse_interrupt",
                    &my_dev_id)) {
        pr_info("Failed to reserve mouse irq %d\n", irq);
        return -1;
    }

    pr_info("Successfully loaded Mouse ISR handler\n");
    return 0;
}

static void __exit my_exit(void)
{
    free_irq(irq, &my_dev_id);
    pr_info("Mouse ISR handler unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

