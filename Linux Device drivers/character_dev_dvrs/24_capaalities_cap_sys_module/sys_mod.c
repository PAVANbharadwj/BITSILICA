#include <stdio.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>


#define init_module(module_image, len, param_values) \
        syscall(__NR_init_module, module_image, len, param_values)

int main(int argc, char **argv)
{
    const char *params = "";
    int fd;
    struct stat st;
    void *image;
    size_t image_size;

    if (argc < 2) {
        printf("Usage: %s <module.ko>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    fstat(fd, &st);
    image_size = st.st_size;

    image = malloc(image_size);
    read(fd, image, image_size);
    close(fd);

    if (init_module(image, image_size, params) != 0) {
        perror("init_module");
        free(image);
        return 1;
    }

    free(image);
    return 0;
}

