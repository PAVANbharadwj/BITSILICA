#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define DEV "/dev/heapdev"

int main()
{
    int fd = open(DEV, O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Allocate HEAP memory
    char *heap_buf = malloc(100);
    if (!heap_buf) return 1;

    strcpy(heap_buf, "This data came from HEAP memory!");

    printf("Sending heap data to kernel...\n");
    write(fd, heap_buf, strlen(heap_buf) + 1);

    free(heap_buf);
    close(fd);
    return 0;
}

