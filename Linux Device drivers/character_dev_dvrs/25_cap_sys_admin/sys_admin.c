#include <stdio.h>
#include <sys/mount.h>
#include <errno.h>

int main(void)
{
    if (mount("tmpfs", "/tmp/mnt", "tmpfs", 0, "") != 0) {
        perror("mount");
        return 1;
    }

    printf("Mounted tmpfs successfully\n");
    return 0;
}

