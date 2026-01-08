#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<unistd.h>

#define IOC_MAGIC 'k'
#define IOCTL_SET_VALUE  _IOW(IOC_MAGIC, 1, int)
#define IOCTL_GET_VALUE  _IOR(IOC_MAGIC, 2, int)
#define IOCTL_CLEAR_VALUE _IO(IOC_MAGIC, 3)

int main(){

	printf("Entered main\n");
	int fd = open("/dev/ioctl_driver",O_RDWR);
	int val;
	if(fd<0){
		printf("Error in opening file");
		return -1;
	}
	scanf("%d",&val);
	ioctl(fd, IOCTL_SET_VALUE, &val);
        printf("Sent value = %d\n", val);

        ioctl(fd, IOCTL_GET_VALUE, &val);
    	printf("Received value = %d\n", val);

    	ioctl(fd, IOCTL_CLEAR_VALUE);
    	printf("Value cleared\n");

    	ioctl(fd, IOCTL_GET_VALUE, &val);
    	printf("After clear, value = %d\n", val);

    	close(fd);
    	return 0;
}


