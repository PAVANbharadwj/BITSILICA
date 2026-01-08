#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>


#define TEMP_IOCTL_MAGIC 'T'
#define TEMP_IOCTL_SET_HIGH _IOW(TEMP_IOCTL_MAGIC, 1, int)
#define TEMP_IOCTL_SET_LOW  _IOW(TEMP_IOCTL_MAGIC, 2, int)

int main()
{
    int fd, ret;
    int alert;
    int high = 40;   
    int low  = 10;   
    printf("Opening /dev/tempsensor...\n");

    fd = open("/dev/tempsensor", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("Setting thresholds:\n");
    printf("  High = %d\n", high);
    printf("  Low  = %d\n", low);

    ioctl(fd, TEMP_IOCTL_SET_HIGH, &high);
    ioctl(fd, TEMP_IOCTL_SET_LOW, &low);

    printf("\nWaiting for alerts... (blocking read)\n");
    printf("Driver will wake this program ONLY when alert occurs.\n");

    while (1) {
        ret = read(fd, &alert, sizeof(alert));
        if (ret < 0) {
            perror("read");
            break;
        }

        printf("\nALERT RECEIVED! Count = %d\n", alert);
        printf("Waiting for next alert...\n");
    }

    close(fd);
    return 0;
}

