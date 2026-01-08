#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEV "/dev/simplechar"

void test_mode(int flags, const char *msg)
{


    int fd = open(DEV, flags);
    if (fd < 0) {
        perror("open");
        return;
    }

    printf("Opened successfully.\n");

    if (flags & (O_WRONLY | O_RDWR)) {
        char text[] = "Testing write...\n";
        write(fd, text, strlen(text));
        printf("Write done.\n");
    }

    close(fd);
    printf("Closed.\n");
}

int main()
{
    printf("User program to test driver open flags\n");

    test_mode(O_RDONLY, "READ ONLY (O_RDONLY)");
    test_mode(O_WRONLY, "WRITE ONLY (O_WRONLY)");
    test_mode(O_RDWR,    "READ/WRITE (O_RDWR)");

    test_mode(O_WRONLY | O_TRUNC,  "TRUNCATE (O_TRUNC)");
    test_mode(O_WRONLY | O_APPEND, "APPEND (O_APPEND)");

    test_mode(O_RDONLY | O_NONBLOCK, "NONBLOCK (O_NONBLOCK)");

    test_mode(O_WRONLY | O_SYNC,     "SYNC MODE (O_SYNC)");
    test_mode(O_WRONLY | O_DSYNC,    "DSYNC MODE (O_DSYNC)");
    test_mode(O_WRONLY | O_RSYNC,    "RSYNC MODE (O_RSYNC)");

    return 0;
}

