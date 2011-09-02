CXX := i586-mingw32msvc-g++
WXCONFIG := /usr/local/i586-mingw32/bin/wx-config

LDFLAGS	:= -Wl,-s

# include path
INCLUDE	+= -I../manual -I../auto
INCLUDE	+= -I../../../../Source/Icons

# librarian
AR	:= ar

# compiler settings
CXXFLAGS += $(shell $(WXCONFIG) --cxxflags base)
CXXFLAGS += $(INCLUDE) -Wall

# linker settings
LDFLAGS	+= $(shell $(WXCONFIG) --libs base)

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

build:	lib$(TARGET).a

clean:
	rm -f lib$(TARGET).a *.o .depend

rebuild: clean build

lib$(TARGET).a:	.depend $(OBJS)
	$(AR) -rs $@ $(OBJS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
