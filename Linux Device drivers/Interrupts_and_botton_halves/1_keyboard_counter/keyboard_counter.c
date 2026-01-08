#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

static int irq = 1;
static int dev = 0xaa;
static int counter = 0;

static irqreturn_t keyboard_handler(int irq, void *dev_id)
{
    pr_info("Keyboard Counter: %d\n", counter++);
    return IRQ_NONE;
}

static int __init test_interrupt_init(void)
{
    pr_info("%s: In init\n", __func__);
    return request_irq(irq, keyboard_handler, IRQF_SHARED,
                       "my_keyboard_handler", &dev);
}

static void __exit test_interrupt_exit(void)
{
    pr_info("%s: In exit\n", __func__);
    synchronize_irq(irq);
    free_irq(irq, &dev);
}

module_init(test_interrupt_init);
module_exit(test_interrupt_exit);

