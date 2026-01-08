#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "mystruct.h"

#define DEVICE_FILE "/dev/mystruct"

int main(void)
{
    int fd;
    struct abc user_struct;   // STRUCT itself is on STACK

    /* -------- HEAP allocation for one member -------- */
    user_struct.str = malloc(10 * sizeof(char));
    strcpy(user_struct.str, "hello");


    user_struct.i = 10;

    printf("Opening file: %s\n", DEVICE_FILE);

    fd = open(DEVICE_FILE, O_RDWR);
    if (fd < 0) {
        perror("open failed");
        free(user_struct.str);
        return 1;
    }

    write(fd, &user_struct, sizeof(user_struct));

    close(fd);
    free(user_struct.str);  // Free HEAP memory

    return 0;
}

