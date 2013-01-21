obj-m := trace2uml_driver.o
trace2uml_driver-y := ../auto/trace2uml_driver.o

KVERSION = $(shell uname -r)
all:
	make -C /lib/modules/$(KVERSION)/build M=$(CURDIR) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(CURDIR) clean
