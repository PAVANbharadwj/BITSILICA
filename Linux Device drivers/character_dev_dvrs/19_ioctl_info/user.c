#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "demo_ioctl.h"
#include<unistd.h>
int main(void)
{
    int fd, val = 10;

    fd = open("/dev/ioctl_info", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    ioctl(fd, IOCTL_SET, &val);

    close(fd);
    return 0;
}

