CXX := i586-mingw32msvc-g++
WXCONFIG := /usr/local/i586-mingw32/bin/wx-config

LDFLAGS	:= -Wl,-s

# include path
INCLUDE	:= -I../manual
INCLUDE	+= -I../../../../Source/Icons

# Graphic Library
GRAPHDIR	:= ../../../components_WGNBOFKH/Component_AstadeGraphLib
GRAPHLIBDIR := $(GRAPHDIR)/Config_MingwCross
GRAPHLIB	:= AstadeGraphLib
INCLUDE	+= -I$(GRAPHDIR)/auto -I$(GRAPHDIR)/manual
LDFLAGS	+= -L$(GRAPHLIBDIR) -l$(GRAPHLIB)

# compiler settings
CXXFLAGS += $(shell $(WXCONFIG) --cxxflags)
CXXFLAGS += $(INCLUDE) -Wall

# linker settings
LDFLAGS	+= $(shell $(WXCONFIG) --libs)

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h $(GRAPHDIR)/auto/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

../../../components_WGNBOFKH/Component_Astade/auto/%_png.h:	../../../../Source/icons_png/%.png
	../../../Components_Helper_components/Component_UIGKBCCK/Config_Windows/bin2c -c $< $@

build:	$(ICONAUTO) $(TARGET).exe

clean:
	rm -f $(TARGET).exe $(TARGET).res *.o .depend

rebuild: clean build

run:
	./$(TARGET).exe

debug:
	insight-x86 $(TARGET).exe

#$(TARGET).res: ../manual/$(TARGET).rc ../../../../Source/Icons/edit.ico
#	i586-mingw32msvc-windres -i ../manual/$(TARGET).rc --input-format=rc -o $(TARGET).res -O coff --include-dir ../../../../Source/Icons --include-dir $(RWX_PATH)/include/wx-$(RWX_VER)

#$(TARGET).exe:	.depend $(TARGET).res $(OBJS) $(GRAPHLIBDIR)/lib$(GRAPHLIB).a
#	$(CXX) -o $@ $(OBJS) $(TARGET).res $(LDFLAGS)
$(TARGET).exe:	.depend $(OBJS) $(GRAPHLIBDIR)/lib$(GRAPHLIB).a
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
