obj-m+=read_write.o
KDIR=/lib/modules/$(shell uname -r)/build
all:
Make -C $(KDIR) M=$(shell pwd) modules
clean:
Make -C $(KDIR) M=$(shell pwd) clean