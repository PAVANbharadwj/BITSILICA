#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/io.h>

MODULE_LICENSE("GPL");

const unsigned char kbdus[128] = {
    0, 27, '1','2','3','4','5','6','7','8','9','0','-','=', '\b',
    '\t',
    'q','w','e','r','t','y','u','i','o','p','[',']','\n',
    0,
    'a','s','d','f','g','h','j','k','l',';','\'','`',
    0,
    '\\','z','x','c','v','b','n','m',',','.','/',
    0,
    '*',
    0,
    ' ',
    0,
    0,0,0,0,0,0,0,0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};

static int irq = 1;
static int dev = 0xaa;

#define KBD_DATA_REG      0x60
#define KBD_SCANCODE_MASK 0x7F
#define KBD_STATUS_MASK   0x80

static irqreturn_t keyboard_handler(int irq, void *dev_id)
{
    unsigned char scancode;

    scancode = inb(KBD_DATA_REG);

    pr_info("Character %c %s\n",
            kbdus[scancode & KBD_SCANCODE_MASK],
            scancode & KBD_STATUS_MASK ? "Released" : "Pressed");

    return IRQ_HANDLED;
}

static int __init test_interrupt_init(void)
{
    pr_info("%s: In init\n", __func__);
    return request_irq(irq, keyboard_handler,
                       IRQF_SHARED,
                       "my_keyboard_handler",
                       &dev);
}

static void __exit test_interrupt_exit(void)
{
    pr_info("%s: In exit\n", __func__);
    synchronize_irq(irq);
    free_irq(irq, &dev);
}

module_init(test_interrupt_init);
module_exit(test_interrupt_exit);

