CXX := i586-mingw32msvc-g++
WXCONFIG := /usr/local/i586-mingw32/bin/wx-config

LDFLAGS	:= -Wl,-s

# include path
INCLUDE	:= -I../manual -I../auto
INCLUDE	+= -I../../../../Source/Icons

# Astade API
APIDIR	:= ../../Component_AstadeAPI
APILIBDIR := $(APIDIR)/Config_AQAHLGFG
APILIB	:= AstadeAPI
INCLUDE	+= -I$(APIDIR)/auto -I$(APIDIR)/manual
LDFLAGS	+= -L$(APILIBDIR) -l$(APILIB)

# compiler settings
CXXFLAGS += $(shell $(WXCONFIG) --cxxflags base)
CXXFLAGS += $(INCLUDE) -Wall

# linker settings
LDFLAGS	+= $(shell $(WXCONFIG) --libs base)

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h $(APIDIR)/auto/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

build:	$(TARGET).exe

clean:
	rm -f $(TARGET).exe *.o .depend

rebuild:	clean build

$(TARGET).exe:	.depend $(OBJS) $(APILIBDIR)/lib$(APILIB).a
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
