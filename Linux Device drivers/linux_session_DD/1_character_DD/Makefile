
# Makefile
obj-m += mychardev.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	$(CC) -Wall -O2 -o test_app test_app.c

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	$(RM) test_app

