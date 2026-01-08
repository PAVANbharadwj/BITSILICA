#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");

#define MAX_IRQS 256

static int irq_ok[MAX_IRQS];
static int dev_id = 1;

static irqreturn_t handler(int irq, void *dev)
{
   // pr_info("Observed IRQ: %d\n", irq);
    return IRQ_NONE; 
}

static int __init myinit(void)
{
    int i, ret;

    for (i = 0; i < MAX_IRQS; i++) {
        ret = request_irq(i, handler, IRQF_SHARED,
                          "irq_observer", &dev_id);
        if (ret == 0) {
            irq_ok[i] = 1;
        } else {
            irq_ok[i] = 0;
        }
    }

    pr_info("IRQ observer loaded\n");
    return 0;
}

static void __exit myexit(void)
{
    int i;

    for (i = 0; i < MAX_IRQS; i++) {
        if (irq_ok[i])
            free_irq(i, &dev_id);
    }
 
    pr_info("IRQ observer unloaded\n");
}

module_init(myinit);
module_exit(myexit);

