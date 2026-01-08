#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEV "/dev/inode_struct"

void test(const char *msg, int flags)
{
    printf("\n========== %s ==========\n", msg);

    int fd = open(DEV, flags);
    if (fd < 0) {
        printf("open() failed: %s\n", strerror(errno));
        return;
    }

    printf("Opened successfully (fd = %d)\n", fd);

    /* Try a write if allowed */
    if (flags & (O_WRONLY | O_RDWR | O_APPEND | O_TRUNC)) {
        char data[] = "User writing to driver...\n";
        write(fd, data, strlen(data));
        printf("Write() done\n");
    }

    close(fd);
    printf("Closed\n");
}

int main()
{
    printf("=== User Program to Test Driver Flags + inode info ===\n");

    test("READ ONLY (O_RDONLY)", O_RDONLY);
    test("WRITE ONLY (O_WRONLY)", O_WRONLY);
    test("READ/WRITE (O_RDWR)", O_RDWR);

    test("TRUNCATE (O_WRONLY | O_TRUNC)", O_WRONLY | O_TRUNC);
    test("APPEND (O_WRONLY | O_APPEND)", O_WRONLY | O_APPEND);

    test("NON-BLOCKING (O_RDONLY | O_NONBLOCK)", O_RDONLY | O_NONBLOCK);

    test("SYNC WRITE (O_WRONLY | O_SYNC)", O_WRONLY | O_SYNC);
    test("DSYNC WRITE (O_WRONLY | O_DSYNC)", O_WRONLY | O_DSYNC);
    test("RSYNC (O_WRONLY | O_RSYNC)", O_WRONLY | O_RSYNC);

    return 0;
}

