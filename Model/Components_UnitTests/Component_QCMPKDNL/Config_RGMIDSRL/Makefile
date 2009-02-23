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

ifdef DEBUG
	CXXFLAGS := -g
	LDFLAGS	:=
	TARGET_DEBUG := yes
else
	CXXFLAGS :=
	LDFLAGS	:= -Wl,-s
endif

WXCONFIG := wx-config --prefix=$(RWX_PATH) --toolkit=${TARGET_TOOLKIT} --universal=${TARGET_UNIV} --static=${TARGET_STATIC} --debug=${TARGET_DEBUG} --version=$(RWX_VER)

# include path
INCLUDE	:= -I../manual

# Graphic Library
GRAPHDIR	:= ../../../components_WGNBOFKH/Component_CDFBZLFN
GRAPHLIBDIR := $(GRAPHDIR)/Config_NWPHOJLA
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

../../../components_WGNBOFKH/component_KSEQOEET/auto/%_png.h:	../../../../Source/icons_png/%.png
	../../../Components_ZFTMQEHP/Component_UIGKBCCK/Config_HFQMMURT/bin2c $< $@

build:	$(ICONAUTO) $(TARGET).exe

clean:
	rm -f $(TARGET).exe *.o .depend

rebuild: clean build

run:
	$(TARGET).exe

debug:
	insight-x86 $(TARGET).exe

$(TARGET).exe:	$(OBJS) $(GRAPHLIBDIR)/lib$(GRAPHLIB).a
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
