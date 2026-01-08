obj-m := hello.o

KDIR := /home/subhash/Documents/workspace/ldd/source/linux_bbb_5.4
PWD  := $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules

clean:
	make -C $(KDIR) M=$(PWD) clean

