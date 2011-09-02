CXX := i586-mingw32msvc-g++
WXCONFIG := /usr/local/i586-mingw32/bin/wx-config

LDFLAGS	:= -Wl,-s

# include path
INCLUDE	:= -I../manual
INCLUDE	+= -I../../../../Source/Icons

ICONSOURCE	:= $(wildcard ../../../../Source/icons_png/*.png)
ICONDEST = $(patsubst %.png,%_png.h,$(ICONSOURCE))
ICONAUTO = $(patsubst ../../../../Source/icons_png%,../../../components_WGNBOFKH/Component_BZBVDSZR/auto%,$(ICONDEST))

# Astade API
APIDIR	:= ../../Component_AstadeAPI
APILIBDIR := $(APIDIR)/Config_MingwCross
APILIB	:= AstadeAPI
INCLUDE	+= -I$(APIDIR)/auto
LDFLAGS	+= -L$(APILIBDIR) -l$(APILIB)

# compiler settings
CXXFLAGS += $(shell $(WXCONFIG) --cxxflags)
CXXFLAGS += $(INCLUDE) -Wall

# linker settings
LDFLAGS	+= $(shell $(WXCONFIG) --libs)

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h $(APIDIR)/auto/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

../../../components_WGNBOFKH/Component_BZBVDSZR/auto/%_png.h: ../../../../Source/icons_png/%.png
	../../../Components_Helper_components/Component_bin2c/Config_Linux/bin2c -c $< $@

build:	$(TARGET).exe

clean:
	rm -f $(TARGET).exe *.o .depend

rebuild: clean build

$(TARGET).res: ../manual/$(TARGET).rc
	i586-mingw32msvc-windres -i ../manual/$(TARGET).rc --input-format=rc -o $(TARGET).res -O coff --include-dir ../../../../Source/Icons --include-dir $(RWX_PATH)/include/wx-$(RWX_VER)

$(TARGET).exe:	.depend $(TARGET).res $(OBJS) $(APILIBDIR)/lib$(APILIB).a
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(ICONAUTO) $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
