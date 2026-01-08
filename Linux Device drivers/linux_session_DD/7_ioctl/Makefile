
obj-m := ioctl_driver.o


KDIR := /lib/modules/$(shell uname -r)/build


PWD := $(shell pwd)


all: module user
	
module:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

user: test_ioctl.c
	gcc -o test_ioctl test_ioctl.c

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -f test_ioctl

