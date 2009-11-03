#
# (C) Copyright 2005,2006 Anders Larsen <al@alarsen.net>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

TARGET	?= Astade
TARGET_TOOLKIT  := msw
TARGET_UNIV := no
TARGET_STATIC := yes
TARGET_DEBUG := no
# DEBUG := 1

# wxWidgets version
# RWX_VER := 2.8 # this should be set as an environment variable
# RWX_PATH := .. #  this should be set as an environment variable

# ***************************************************

# check make target
$(if $(TARGET),,$(error Variable TARGET not defined))

ifdef DEBUG
	CXXFLAGS := -g
	LDFLAGS	:=
	TARGET_DEBUG := yes
else
	CXXFLAGS :=
	LDFLAGS	:= -Wl,-s
endif

TRACE_LIST :=$(addsuffix .o,$(TRACECLASSES))

WXCONFIG := wx-config --prefix=$(RWX_PATH) --toolkit=${TARGET_TOOLKIT} --universal=${TARGET_UNIV} --static=${TARGET_STATIC} --debug=${TARGET_DEBUG} --version=$(RWX_VER)

# include path
INCLUDE	:= -I../manual -I../auto
INCLUDE	+= -I../../../../Source/Icons
INCLUDE += -I$(BOOSTPATH)

ICONSOURCE	:= $(wildcard ../../../../Source/icons_png/*.png)
ICONDEST = $(patsubst %.png,%_png.h,$(ICONSOURCE))
ICONAUTO = $(patsubst ../../../../Source/icons_png%,../../../components_WGNBOFKH/component_KSEQOEET/auto%,$(ICONDEST))

# Astade API
APIDIR	:= ../../Component_AstadeAPI
APILIBDIR := $(APIDIR)/Config_ZMSNZKTV
APILIB	:= AstadeAPI
INCLUDE	+= -I$(APIDIR)/auto -I$(APIDIR)/manual
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
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(if $(findstring $(notdir $@),$(TRACE_LIST)),-D"_TRACE_" -include wxTrace2file.h,) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

../../../components_WGNBOFKH/component_KSEQOEET/auto/%_png.h:	../../../../Source/icons_png/%.png
	../../../Components_ZFTMQEHP/Component_UIGKBCCK/Config_HFQMMURT/bin2c -c $< $@

build:	$(TARGET).exe

clean:
	rm -f $(TARGET).exe $(TARGET).res *.o .depend

rebuild: clean build

run:
	$(TARGET).exe

debug:
	insight-x86 $(TARGET).exe

$(TARGET).res: ../manual/$(TARGET).rc ../../../../Source/Icons/Astade.ico
	windres.exe -i ../manual/$(TARGET).rc --input-format=rc -o $(TARGET).res -O coff --include-dir ../../../../Source/Icons --include-dir $(RWX_PATH)/include/wx-$(RWX_VER)

$(TARGET).exe:	.depend $(TARGET).res $(OBJS) $(APILIBDIR)/lib$(APILIB).a
	$(CXX) -o $@ $(OBJS) $(TARGET).res $(LDFLAGS)

.depend:	Makefile $(ICONAUTO) $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
