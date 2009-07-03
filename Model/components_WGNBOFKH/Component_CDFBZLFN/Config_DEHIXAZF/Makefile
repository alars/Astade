DEBUG	:= 1

# make target
$(if $(TARGET),,$(error Variable TARGET not defined))

# installation path
prefix	?= /usr

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
	install -d $(prefix)/include/$(TARGET)
	install ../auto/*.h $(prefix)/include/$(TARGET)
	install -d $(prefix)/lib
	install lib$(TARGET).a $(prefix)/lib
	strip --strip-debug $(prefix)/lib/lib$(TARGET).a

clean:
	rm -f lib$(TARGET).a *.o .depend

rebuild:	clean build

lib$(TARGET).a:	.depend $(OBJS)
	$(AR) -rs $@ $(OBJS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
