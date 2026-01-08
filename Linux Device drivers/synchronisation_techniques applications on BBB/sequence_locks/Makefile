obj-m := seq_locks.o

KDIR := /home/subhash/Documents/workspace/ldd/source/linux_bbb_5.4
PWD  := $(shell pwd)


all:
	make -C $(KDIR) M=$(PWD) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules

clean:
	make -C $(KDIR) M=$(PWD) cleans

copy-dtb:
	scp /home/subhash/Documents/workspace/ldd/source/linux_bbb_5.4/arch/arm/boot/dts/am335x-boneblack.dtb debian@192.168.7.2:/home/debian/drivers

copy-drv:
	scp *.ko debian@192.168.7.2:/home/debian/drivers/synchronisation_techniques
