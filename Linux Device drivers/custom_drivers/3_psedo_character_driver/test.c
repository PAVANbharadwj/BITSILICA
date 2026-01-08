#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

/* Helper macro */
#define TRY(msg, expr)                     \
    do {                                  \
        if ((expr) < 0)                   \
            perror(msg);                  \
        else                              \
            printf("%s: OK\n", msg);      \
    } while (0)

int main(void)
{
    int fd;
    char buf[100];

    printf("\n=== Testing RDWR device (/dev/pcd-2) ===\n");

    fd = open("/dev/pcd-2", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    TRY("write", write(fd, "Hello Kernel Driver", 20));

    lseek(fd, 0, SEEK_SET);
    memset(buf, 0, sizeof(buf));

    TRY("read", read(fd, buf, sizeof(buf)));
    printf("read data: \"%s\"\n", buf);

    printf("\nTesting llseek...\n");
    lseek(fd, 6, SEEK_SET);
    memset(buf, 0, sizeof(buf));
    read(fd, buf, 6);
    printf("after seek read: \"%s\"\n", buf);

    close(fd);

    /* ---------------- Permission tests ---------------- */

    printf("\n=== Testing RDONLY device (/dev/pcd-0) ===\n");
    fd = open("/dev/pcd-0", O_RDONLY);
    if (fd >= 0) {
        memset(buf, 0, sizeof(buf));
        read(fd, buf, sizeof(buf));
        printf("read OK from RDONLY device\n");
        close(fd);
    } else {
        perror("open RDONLY");
    }

    fd = open("/dev/pcd-0", O_WRONLY);
    if (fd < 0)
        perror("write open blocked (expected)");
    else
        close(fd);

    printf("\n=== Testing WRONLY device (/dev/pcd-1) ===\n");
    fd = open("/dev/pcd-1", O_WRONLY);
    if (fd >= 0) {
        write(fd, "WRITE ONLY", 10);
        printf("write OK to WRONLY device\n");
        close(fd);
    } else {
        perror("open WRONLY");
    }

    fd = open("/dev/pcd-1", O_RDONLY);
    if (fd < 0)
        perror("read open blocked (expected)");
    else
        close(fd);

    printf("\n=== Testing independent buffers ===\n");

    fd = open("/dev/pcd-2", O_RDWR);
    write(fd, "DEV2", 4);
    close(fd);

    fd = open("/dev/pcd-3", O_RDONLY);
    read(fd, buf, sizeof(buf));
    printf("pcd-3 contains: \"%s\"\n", buf);
    close(fd);

    printf("\nAll tests completed\n");
    return 0;
}

