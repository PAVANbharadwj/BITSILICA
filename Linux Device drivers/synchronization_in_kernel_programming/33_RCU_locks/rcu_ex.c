#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/rcupdate.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

struct task_struct *thread;

typedef struct my_data {
    int key;
    int val;
} my_data;

my_data *global_ptr = NULL;

static int write_thread_fn(void *arg)
{
    my_data *new_ptr;

    new_ptr = kmalloc(sizeof(my_data), GFP_KERNEL);
    new_ptr->key = 10;
    new_ptr->val = 1000;

    rcu_assign_pointer(global_ptr, new_ptr);

    pr_info("writer: updated global_ptr key=%d val=%d\n",
            global_ptr->key, global_ptr->val);

    return 0;
}


static int read_thread_fn(void *arg)
{
    my_data *ptr;

    rcu_read_lock();
    ptr = rcu_dereference(global_ptr);
    if (ptr)
        pr_info("reader: key=%d val=%d\n", ptr->key, ptr->val);
    rcu_read_unlock();

    return 0;
}


static int __init test_hello_init(void)
{
    thread = kthread_run(write_thread_fn, NULL, "write_thread");
    msleep(1000);
    kthread_run(read_thread_fn, NULL, "read_thread");
    return 0;
}

static void __exit test_hello_exit(void)
{
    my_data *old;

    old = rcu_dereference_protected(global_ptr, 1);
    if (old) {
        synchronize_rcu();
        kfree(old);
    }

    pr_info("module exit\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);

