#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd = open("/dev/strlen_demo", O_WRONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    write(fd, "Hello Kernel", strlen("Hello Kernel"));

    close(fd);
    return 0;
}

