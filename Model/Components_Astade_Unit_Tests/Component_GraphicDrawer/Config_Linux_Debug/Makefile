DEBUG	:= 1

# make target
$(if $(TARGET),,$(error Variable TARGET not defined))

# installation path
prefix	?= ~

# Astade API
APIDIR	:= ../../../components_WGNBOFKH/Component_AstadeGraphLib
APILIBDIR := $(APIDIR)/Config_Linux_Statlib
APILIB	:= AstadeGraphLib

# include path
INCLUDE	+= -I../manual -I../auto
INCLUDE	+= -I$(APIDIR)/auto -I$(APIDIR)/manual

# compiler settings
WXCONFIG := wx-config
CXXFLAGS:= $(INCLUDE) $(shell ${WXCONFIG} --cxxflags) -Wall
LDFLAGS	:= -L$(APILIBDIR) -l$(APILIB) $(shell ${WXCONFIG} --libs)

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

build: $(TARGET)  

install:	build
	install -s $(TARGET) $(prefix)/bin
	
clean:
	rm -f $(TARGET) *.o .depend

rebuild: clean build

run:
	./$(TARGET)

debug:
	insight ./$(TARGET)

$(TARGET): $(OBJS) $(APILIBDIR)/lib$(APILIB).a
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(ICONAUTO) $(SVGICONAUTO) $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
