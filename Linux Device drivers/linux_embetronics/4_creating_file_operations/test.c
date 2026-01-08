#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd = open("/dev/simplechar", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    char buf[100];

    write(fd, "HelloKernel", 11);

    lseek(fd, 0, SEEK_SET);
    read(fd, buf, 100);

    printf("Read: %s\n", buf);

    close(fd);
    return 0;
}

