#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/rcupdate.h>
#include <linux/kthread.h>

MODULE_LICENSE("GPL");

struct task_struct *thread;

typedef struct my_data {
    int key;
    int val;
} my_data;

my_data *global_ptr = NULL;

static int read_thread_fn(void *arg)
{
    my_data *ptr = NULL;

    rcu_read_lock();
    ptr = rcu_dereference(global_ptr);
    if (ptr)
        pr_info("%s: key:%d val:%d\n", __func__, ptr->key, ptr->val);
    rcu_read_unlock();

    return 0;
}

static int __init test_hello_init(void)
{
    global_ptr = kmalloc(sizeof(my_data), GFP_KERNEL);
    if (!global_ptr)
        return -ENOMEM;

    global_ptr->key = 1;
    global_ptr->val = 1000;

    thread = kthread_run(read_thread_fn, NULL, "read_thread");
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
}

module_init(test_hello_init);
module_exit(test_hello_exit);

