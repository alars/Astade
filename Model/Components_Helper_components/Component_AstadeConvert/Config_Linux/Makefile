DEBUG	:= 1

# installation path
prefix	?= ~

# include path
INCLUDE	:= -I../manual
INCLUDE	+= -I../../../../Source/Icons

# Astade API
APIDIR	:= ../../../Components_Astade_components/Component_AstadeAPI
APILIBDIR := $(APIDIR)/Config_Linux_StatLib
APILIB	:= AstadeAPI
INCLUDE	+= -I$(APIDIR)/auto -I$(APIDIR)/manual

# compiler settings
CXXFLAGS:= $(INCLUDE) $(shell wx-config --cxxflags base) -Wall
LDFLAGS	:= -L$(APILIBDIR) -l$(APILIB) $(shell wx-config --libs base)

ifdef DEBUG
CXXFLAGS+= -g
else
LDFLAGS	+= -Wl,-s
endif

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h $(APIDIR)/auto/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

build:	$(TARGET)

install:	build
	install -s $(TARGET) $(prefix)/bin

clean:
	rm -f $(TARGET) *.o .depend

rebuild:	clean build

$(TARGET):	.depend $(OBJS) $(APILIBDIR)/lib$(APILIB).a
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
