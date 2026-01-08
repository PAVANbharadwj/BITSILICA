#ifndef THREE_IOCTL_H
#define THREE_IOCTL_H

#include <linux/ioctl.h>

#define MY_MAGIC 'M'

#define IOCTL_SET_VAL    _IOW(MY_MAGIC, 1, int)
#define IOCTL_GET_VAL    _IOR(MY_MAGIC, 2, int)
#define IOCTL_CLEAR_VAL  _IO(MY_MAGIC,  3)

#endif

