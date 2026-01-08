#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/percpu.h>
#include <linux/smp.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pavan");
MODULE_DESCRIPTION("Simple per-CPU variable demo");


DEFINE_PER_CPU(int, cpu_counter);

static int __init percpu_demo_init(void)
{
    int cpu;

    pr_info("percpu_demo: module loaded\n");


    for_each_online_cpu(cpu) {
        per_cpu(cpu_counter, cpu)++;
    }


    for_each_online_cpu(cpu) {
        pr_info("CPU %d counter = %d\n",
                cpu, per_cpu(cpu_counter, cpu));
    }

    return 0;
}

static void __exit percpu_demo_exit(void)
{
    int cpu;

    pr_info("percpu_demo: module unloaded\n");

    for_each_online_cpu(cpu) {
        pr_info("Final CPU %d counter = %d\n",
                cpu, per_cpu(cpu_counter, cpu));
    }
}

module_init(percpu_demo_init);
module_exit(percpu_demo_exit);

