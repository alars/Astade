TRACE_LIST :=$(addsuffix .o,$(TRACECLASSES))

#set trace on
ccflags-y += -D"_TRACE_" -include trace.h
ccflags-y += -I$(src)/../manual

obj-m := trace_test.o
trace_test-y := ../auto/trace_test.o

KVERSION = $(shell uname -r)
all:
	make -C /lib/modules/$(KVERSION)/build M=$(CURDIR) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(CURDIR) clean
