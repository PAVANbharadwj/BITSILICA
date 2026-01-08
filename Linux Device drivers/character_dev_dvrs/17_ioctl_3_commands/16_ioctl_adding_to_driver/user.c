#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "simple_ioctl.h"

int main()
{
    int fd;
    int value;

    fd = open("/dev/simple_ioctl", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    /* SET value */
    value = 123;
    ioctl(fd, IOCTL_SET_VALUE, &value);

    /* GET value */
    value = 0;
    ioctl(fd, IOCTL_GET_VALUE, &value);

    printf("User: value received = %d\n", value);

    close(fd);
    return 0;
}

