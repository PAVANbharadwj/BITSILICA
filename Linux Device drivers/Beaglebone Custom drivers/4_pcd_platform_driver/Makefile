obj-m += pcd_device_setup.o
obj-m += pcd_platform_driver.o

KDIR ?= /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)
HOST_KERN_DIR = /lib/modules/$(shell uname -r)/build/

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean

host:
	make -C $(HOST_KERN_DIR) M=$(PWD) modules
