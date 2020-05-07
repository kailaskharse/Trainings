obj-m := kprobe2.o 
KDIR= /home/$(USER)/KM_GIT/elinux/kernel-bbb-3.14/

all:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C $(KDIR) M=`pwd` modules

clean:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C $(KDIR) M=`pwd` clean
