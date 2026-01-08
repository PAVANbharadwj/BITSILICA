#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");

static int __init fmt_init(void)
{
    dev_t dev;
    char buf[32];

    /* Create a device number */
    dev = MKDEV(240, 3);

    /* Convert dev_t → string */
    format_dev_t(buf, dev);

    pr_info("Formatted dev_t: %s\n", buf);

    return 0;
}

static void __exit fmt_exit(void)
{
    pr_info("format_dev_t module unloaded\n");
}

module_init(fmt_init);
module_exit(fmt_exit);

