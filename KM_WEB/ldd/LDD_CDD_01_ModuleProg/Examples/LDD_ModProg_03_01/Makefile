obj-m := add.o avg.o

KERNEL_DIR = /lib/modules/`uname -r`/build

PWD = $(shell pwd)

all:
	make -C $(KERNEL_DIR) M=$(PWD) modules

install:
	make -C $(KERNEL_DIR) M=$(PWD) modules_install
	depmod -a

clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean
