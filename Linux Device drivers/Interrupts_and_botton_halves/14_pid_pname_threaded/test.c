#include <linux/module.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/irqflags.h>
#include<linux/interrupt.h>

static int irq = 1,my_dev_id,irq_counter = 0;

module_param(irq,int,S_IRUGO);



static irqreturn_t my_interrupt(int irq,void *dev_id){
	pr_info("%s\n",__func__);

	return IRQ_WAKE_THREAD;
}
static irqreturn_t my_threaded_interrupt(int irq,void *dev_id){
        pr_info("COMM:%s\tPID:%d",current->comm,current->pid);
        return IRQ_NONE;
}
static int __init my_init(void)
{
    int ret;
 
    ret = (request_threaded_irq(irq,my_interrupt,my_threaded_interrupt,IRQF_SHARED,"my_interrupt",&my_dev_id));
    if(ret != 0){
	pr_info("Failed to reserve irq %d\n",irq);
	return -1;
    }
    
    pr_info("Successfully loading ISR Handler\n");
    return 0;
}

static void __exit my_exit(void)
{

	synchronize_irq(irq);
	free_irq(irq,&my_dev_id);
	pr_info("Sussessfully unloaded module, irq_counter - %d\n",irq_counter);
}

MODULE_LICENSE("GPL");
module_init(my_init);
module_exit(my_exit);

