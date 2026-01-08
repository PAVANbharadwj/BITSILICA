#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "mystruct.h"

#define DEV "/dev/structdev"

int main()
{
    int fd = open(DEV, O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct mydata udata;

    /* Fill the structure */
    udata.id = 101;
    udata.value = 500;
    strcpy(udata.name, "Pavan");

    /* -------- Send structure to kernel -------- */
    printf("Sending struct to kernel...\n");
    write(fd, &udata, sizeof(udata));

    /* -------- Read back from kernel -------- */
    struct mydata rdata;
    printf("Reading struct from kernel...\n");
    read(fd, &rdata, sizeof(rdata));

    printf("\nUser received:\n");
    printf("id    = %d\n", rdata.id);
    printf("value = %d\n", rdata.value);
    printf("name  = %s\n", rdata.name);

    close(fd);
    return 0;
}

