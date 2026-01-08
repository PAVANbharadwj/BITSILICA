#ifndef SIMPLE_IOCTL_H
#define SIMPLE_IOCTL_H

#include <linux/ioctl.h>

#define IOCTL_MAGIC 'x'

#define IOCTL_SET_VALUE  _IOW(IOCTL_MAGIC, 1, int)
#define IOCTL_GET_VALUE  _IOR(IOCTL_MAGIC, 2, int)

#endif

