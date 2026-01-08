#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fs.h>

int main(void)
{
    int fd;
    unsigned long num_blocks;

    /* Open block device */
    fd = open("/dev/sda1", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    /* BLKGETSIZE returns number of 512-byte blocks */
    if (ioctl(fd, BLKGETSIZE, &num_blocks) < 0) {
        perror("ioctl");
        close(fd);
        return 1;
    }

    printf("Number of blocks: %lu, this makes %.3f GB\n",
           num_blocks,
           (double)num_blocks * 512.0 / (1024 * 1024 * 1024));

    close(fd);
    return 0;
}

