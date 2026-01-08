#include <linux/kernel.h>
#include <linux/module.h>
#include <generated/utsrelease.h>   // For UTS_RELEASE

MODULE_LICENSE("GPL");

static int __init uts_release_init(void)
{
    pr_info("UTS_RELEASE: %s\n", UTS_RELEASE);
    return 0;
}

static void __exit uts_release_exit(void)
{
    pr_info("Module exit\n");
}

module_init(uts_release_init);
module_exit(uts_release_exit);

