DEBUG	:= 1

# include path
INCLUDE	+= -I../manual -I../auto

# librarian
AR	:= ar

# compiler settings
WXCONFIG := wx-config
CXXFLAGS:= $(INCLUDE) $(shell ${WXCONFIG} --cxxflags) -Wall

TRACE_LIST :=$(addsuffix .o,$(TRACECLASSES))

ifdef DEBUG
CXXFLAGS+= -g
else
LDFLAGS	+= -Wl,-s
endif

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(if $(findstring $(notdir $@),$(TRACE_LIST)),-D"_TRACE_" -include wxTrace2file.h,) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

build:	lib$(TARGET).a

install:	build
	mkdir -p /usr/include/$(TARGET)
	mkdir -p /usr/lib
	cp ../auto/*.h /usr/include/$(TARGET)
	cp lib$(TARGET).a /usr/lib

clean:
	rm -f lib$(TARGET).a *.o .depend

rebuild:	clean build

lib$(TARGET).a:	.depend $(OBJS)
	$(AR) -rs $@ $(OBJS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
