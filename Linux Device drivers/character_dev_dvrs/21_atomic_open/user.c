#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/singleopen"

void *func(void *arg)
{
    int fd;

    fd = open(DEVICE_FILE, O_RDWR);
    if (fd < 0) {
        printf("Thread id: %lu failed to open file\n",
               pthread_self());
        return NULL;
    } else {
        printf("Thread id: %lu successfully opened file\n",
               pthread_self());
    }

    /* Keep device open so second thread hits -EBUSY */
    sleep(5);

    write(fd, "hello world", sizeof("hello world"));
    close(fd);

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, func, NULL);
    pthread_create(&thread2, NULL, func, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

