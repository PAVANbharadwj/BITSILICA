#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    printf("Process 2: trying to open device...\n");

    int fd = open("/dev/mutexdev", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("Process 2: acquired device! Holding for 5 seconds...\n");
    sleep(5);

    printf("Process 2: releasing device\n");
    close(fd);

    return 0;
}


