// test_app.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define DEVICE_PATH "/dev/mychardev"

int main(void)
{
    int fd;
    ssize_t ret;
    char write_buf[] = "Hello from user space!";
    char read_buf[1024];

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("Opened %s\n", DEVICE_PATH);

    /* Write to device */
    ret = write(fd, write_buf, strlen(write_buf));
    if (ret < 0) {
        perror("write");
        close(fd);
        return 1;
    }
    printf("Wrote %zd bytes: '%s'\n", ret, write_buf);

    /* Reset file offset to start */
    if (lseek(fd, 0, SEEK_SET) < 0) {
        perror("lseek");
        close(fd);
        return 1;
    }

    /* Read back */
    memset(read_buf, 0, sizeof(read_buf));
    ret = read(fd, read_buf, sizeof(read_buf) - 1);
    if (ret < 0) {
        perror("read");
        close(fd);
        return 1;
    }

    printf("Read %zd bytes: '%s'\n", ret, read_buf);

    close(fd);
    return 0;
}

