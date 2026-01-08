#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "three_ioctl.h"

int main()
{
    int fd;
    int value;

    fd = open("/dev/three_ioctl", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    /* SET value */
    value = 42;
    ioctl(fd, IOCTL_SET_VAL, &value);

    /* GET value */
    value = 0;
    ioctl(fd, IOCTL_GET_VAL, &value);
    printf("User: value = %d\n", value);

    /* CLEAR value */
    ioctl(fd, IOCTL_CLEAR_VAL);

    /* GET again */
    ioctl(fd, IOCTL_GET_VAL, &value);
    printf("User after clear: value = %d\n", value);

    close(fd);
    return 0;
}

