#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <sys/wait.h>

#define SMART_LIGHT_MAGIC 'L'
#define IOCTL_SET_BRIGHTNESS    _IOW(SMART_LIGHT_MAGIC, 3, int)
#define IOCTL_GET_STATE         _IOR(SMART_LIGHT_MAGIC, 6, struct light_state_user)

struct light_state_user {
    int brightness;
    int temperature;
    int is_on;
};

void set_brightness(int value)
{
    int fd = open("/dev/smartLED", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    ioctl(fd, IOCTL_SET_BRIGHTNESS, &value);
    close(fd);
}

int get_brightness(void)
{
    int fd;
    struct light_state_user s;

    fd = open("/dev/smartLED", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    ioctl(fd, IOCTL_GET_STATE, &s);
    close(fd);

    return s.brightness;
}

int main()
{
    pid_t p1, p2;

    printf("Starting testing...\n");

    p1 = fork();

    if (p1 == 0) {
        set_brightness(50);
        exit(0);
    }

    p2 = fork();

    if (p2 == 0) {

        set_brightness(75);
        exit(0);
    }

    wait(NULL);
    wait(NULL);


    int final = get_brightness();


    printf("Final brightness: %d\n", final);
    printf("Expected: Either 50 OR 75\n");

    if (final == 50 || final == 75)
        printf("Atomic update working correctly\n");
    else
        printf("Invalid intermediate value detected!\n");

    return 0;
}

