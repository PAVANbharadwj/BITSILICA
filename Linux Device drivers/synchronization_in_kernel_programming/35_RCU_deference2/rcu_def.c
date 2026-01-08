#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/rcupdate.h>
#include <linux/kthread.h>

MODULE_LICENSE("GPL");

struct task_struct *thread1, *thread2, *thread3;

typedef struct my_data {
    int key;
    int val;
} my_data;

my_data *global_ptr = NULL;

static int write_thread_fn(void *arg)
{
    my_data *new_ptr;

    new_ptr = kmalloc(sizeof(my_data), GFP_KERNEL);
    new_ptr->key = 1;
    new_ptr->val = 1000;

    rcu_assign_pointer(global_ptr, new_ptr);

    pr_info("global pointer key:%d val:%d\n",
            global_ptr->key, global_ptr->val);

    return 0;
}

static int read_thread_fn(void *arg)
{
    my_data *ptr = NULL;

    rcu_read_lock();
    ptr = rcu_dereference(global_ptr);
    if (ptr != NULL)
        pr_info("%s: key:%d val:%d\n", __func__, ptr->key, ptr->val);
    else
        pr_info("%s: write thread did not yet start\n", __func__);
    rcu_read_unlock();

    return 0;
}

static int __init test_hello_init(void)
{
    thread1 = kthread_run(read_thread_fn, NULL, "read_thread1");
    thread2 = kthread_run(write_thread_fn, NULL, "write_thread");
    thread3 = kthread_run(read_thread_fn, NULL, "read_thread2");
    return 0;
}

static void __exit test_hello_exit(void)
{
    my_data *old;

    kthread_stop(thread1);
    kthread_stop(thread2);
    kthread_stop(thread3);

    old = rcu_dereference_protected(global_ptr, 1);
    if (old) {
        synchronize_rcu();
        kfree(old);
    }
}

module_init(test_hello_init);
module_exit(test_hello_exit);

