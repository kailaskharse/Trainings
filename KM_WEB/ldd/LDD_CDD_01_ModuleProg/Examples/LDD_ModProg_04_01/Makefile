obj-m := startstop.o
startstop-objs := start1.o stop1.o

KERNELDIR = /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -rf *.ko *.o *.mod.c *.symvers 

