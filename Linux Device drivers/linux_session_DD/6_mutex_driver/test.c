#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    printf("Process 1: trying to open device...\n");

    int fd = open("/dev/mutexdev", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("Process 1: acquired device! Holding for 10 seconds...\n");
    sleep(10);

    printf("Process 1: releasing device\n");
    close(fd);

    return 0;
}

