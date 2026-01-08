#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>

MODULE_LICENSE("GPL");

static int __init kernel_version_init(void)
{
    pr_info("Kernel Version Code (raw): %u\n", LINUX_VERSION_CODE);

    pr_info("Kernel Version: %d.%d.%d\n",
            (LINUX_VERSION_CODE >> 16) & 0xFF,   // major
            (LINUX_VERSION_CODE >> 8) & 0xFF,    // minor
            LINUX_VERSION_CODE & 0xFF);          // patch

    return 0;
}

static void __exit kernel_version_exit(void)
{
    pr_info("Kernel version module exiting.\n");
}

module_init(kernel_version_init);
module_exit(kernel_version_exit);

