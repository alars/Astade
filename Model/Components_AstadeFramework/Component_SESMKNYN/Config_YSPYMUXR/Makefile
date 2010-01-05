# include path
INCLUDE	:= -I../manual -I../auto

# check make target
$(if $(TARGET),,$(error Variable TARGET not defined))

# compiler settings
CXXFLAGS:= $(INCLUDE) -Wall -DLINUX
LDFLAGS	:= 

ifdef DEBUG
CXXFLAGS+= -g
else
CXXFLAGS+= -O2
LDFLAGS	+= -Wl,-s
endif

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.c ../manual/*.c)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.c=.o))

%.o:	../auto/%.c
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.c
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

build:	$(TARGET)

clean:
	rm -f $(TARGET) *.o .depend

rebuild:	clean build

run:
	./$(TARGET)

$(TARGET):	.depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
