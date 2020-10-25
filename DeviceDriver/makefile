Ifneq ($(KERNELRELEASE),)
Obj-m:=usb_register.o
Else
KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
Default:
$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
