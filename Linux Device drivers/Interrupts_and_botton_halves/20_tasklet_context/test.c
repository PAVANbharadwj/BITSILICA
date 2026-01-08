#include <linux/module.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/irqflags.h>
#include<linux/interrupt.h>
#include <linux/slab.h>


unsigned int irq = 1;

module_param(irq,int,0);
static char tasklet_data[] = "linux kernel is very easy";

void print_context(void){

        if(in_irq()){
                pr_info("Code is running in hard irq context\n");
        }
        else{
                pr_info("Code is not running in hard irq context\n");
        }
}


void tasklet_function(unsigned long data){

	pr_info("%s:data:%s\n",__func__,(char*)data);
        print_context(); 
	return;
}

static struct tasklet_struct *my_tasklet;


static int __init my_init(void)
{
    pr_info("module is loaded on processor:%d\n", smp_processor_id());
    my_tasklet = kmalloc(sizeof(struct tasklet_struct),GFP_KERNEL);
    tasklet_init(my_tasklet, tasklet_function,(unsigned long)tasklet_data);
    tasklet_schedule(my_tasklet);
    return 0;
}

static void __exit my_exit(void)
{
	tasklet_kill(my_tasklet);
    kfree(my_tasklet);

    pr_info("%s: In exit\n", __func__);

}

MODULE_LICENSE("GPL");
module_init(my_init);
module_exit(my_exit);

