#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int arr[5] = {1, 2, 3, 4, 5};
static int count = 0;

/* Expose array to module params */
module_param_array(arr, int, &count, 0644);
MODULE_PARM_DESC(arr, "An integer array");

static int __init my_init(void)
{
    int i;

    pr_info("Module loaded\n");
    pr_info("Number of elements passed = %d\n", count);

    for (i = 0; i < count; i++)
        pr_info("arr[%d] = %d\n", i, arr[i]);

    return 0;
}

static void __exit my_exit(void)
{
    pr_info("Module removed\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");

