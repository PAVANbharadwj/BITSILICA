#ifndef DEMO_IOCTL_H
#define DEMO_IOCTL_H

#include <linux/ioctl.h>

#define DEMO_MAGIC 'D'

#define IOCTL_SET _IOW(DEMO_MAGIC, 1, int)
#define IOCTL_GET _IOR(DEMO_MAGIC, 2, int)
#define IOCTL_CLR _IO(DEMO_MAGIC,  3)

#endif

