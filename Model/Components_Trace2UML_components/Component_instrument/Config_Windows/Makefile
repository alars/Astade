TARGET_ARCH := i586-pc-mingw32
TARGET_GUI  := msw

#DEBUG := 1

ifdef DEBUG
	CXXFLAGS := -g
	LDFLAGS	:=
	WXBUILD := debug
else
	CXXFLAGS :=
	LDFLAGS	:= -Wl,-s
	WXBUILD := release
endif

# include path
INCLUDE	:= -I../manual -I$(BOOSTPATH)

# compiler settings
CXXFLAGS := $(INCLUDE) -Wall -fno-strict-aliasing


# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

all:	$(TARGET).exe

clean:
	rm -f $(TARGET).exe *.o .depend

$(TARGET).exe:	.depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
