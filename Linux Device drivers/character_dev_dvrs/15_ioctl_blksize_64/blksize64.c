#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fs.h>
#include <stdint.h>

int main(void)
{
    int fd;
    uint64_t size;

    fd = open("/dev/sda1", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    /* BLKGETSIZE64 returns size in bytes */
    if (ioctl(fd, BLKGETSIZE64, &size) < 0) {
        perror("ioctl");
        close(fd);
        return 1;
    }

    printf("Size %lu GB\n", size / (1024UL * 1024 * 1024));

    close(fd);
    return 0;
}

