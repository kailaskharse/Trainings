obj-m += gpio_int.o

ARCH=arm
CROSS_COMPILE=arm-linux-gnueabihf-

all:
	make ARCH=${ARCH} CROSS_COMPILE=${CROSS_COMPILE} -C ~/KM_GIT/km-elinux/kernel-3.14/ M=`pwd` modules
 
clean:
	make ARCH=${ARCH} CROSS_COMPILE=${CROSS_COMPILE} -C ~/KM_GIT/km-elinux/kernel-3.14/ M=`pwd` clean
