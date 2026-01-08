#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>

MODULE_LICENSE("GPL");

atomic_t val = ATOMIC_INIT(0);

static int __init test_hello_init(void)
{
    pr_info("%s: Value after initialization: %d\n", __func__, atomic_read(&val));

    atomic_set(&val, 4);
    pr_info("%s: Value after setting to 4: %d\n", __func__, atomic_read(&val));

    atomic_dec(&val);
    pr_info("%s: Value after decrementing: %d\n", __func__, atomic_read(&val));

    atomic_inc(&val);
    pr_info("%s: Value after incrementing: %d\n", __func__, atomic_read(&val));

    atomic_add(3, &val);
    pr_info("%s: Value after adding 3: %d\n", __func__, atomic_read(&val));

    atomic_sub(2, &val);
    pr_info("%s: Value after subtracting 2: %d\n", __func__, atomic_read(&val));

    return -1;
}

static void __exit test_hello_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

