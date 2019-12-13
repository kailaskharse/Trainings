obj-m := km1.o

KER_DIR=/lib/modules/`uname -r`/build
PWD=`pwd`

all:
	make -C $(KER_DIR) M=$(PWD) modules

clean:
	make -C $(KER_DIR) M=$(PWD) clean

install:
	make -C $(KER_DIR) M=$(PWD) modules_install

