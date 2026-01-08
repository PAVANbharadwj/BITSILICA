#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define IOCTL_MAGIC 'k'
#define IOCTL_SET_VAL _IOW(IOCTL_MAGIC, 0, int)
#define IOCTL_GET_VAL _IOR(IOCTL_MAGIC, 1, int)
#define IOCTL_CLEAR   _IO(IOCTL_MAGIC, 2)





int main(void)
{
    const char *dev = "/dev/simple_ioctl";
    int fd = open(dev, O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    int v = 12345;
    if (ioctl(fd, IOCTL_SET_VAL, &v) < 0) {
        perror("ioctl set");
        close(fd);
        return 1;
    }
    printf("Wrote %d to driver\n", v);

    v = 0;
    if (ioctl(fd, IOCTL_GET_VAL, &v) < 0) {
        perror("ioctl get");
        close(fd);
        return 1;
    }
    printf("Read %d from driver\n", v);

    if (ioctl(fd, IOCTL_CLEAR) < 0) {
        perror("ioctl clear");
        close(fd);
        return 1;
    }
    printf("Cleared driver value\n");

    close(fd);
    return 0;
}

