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

DEBUG	:= 1

# make target
$(if $(TARGET),,$(error Variable TARGET not defined))

# installation path
prefix	?= ~

# Astade API
APIDIR	:= ../../Component_AstadeAPI
APILIBDIR := $(APIDIR)/Config_Linux_StatLib
APILIB	:= AstadeAPI

# include path
INCLUDE	+= -I../manual -I../auto
INCLUDE	+= -I../../../../Source/Icons
INCLUDE	+= -I$(APIDIR)/auto -I$(APIDIR)/manual

ICONSOURCE	:= $(wildcard ../../../../Source/icons_png/*.png)
ICONDEST = $(patsubst %.png,%_png.h,$(ICONSOURCE))
ICONAUTO = $(patsubst ../../../../Source/icons_png%,../../../components_WGNBOFKH/component_KSEQOEET/auto%,$(ICONDEST))

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

../../../components_WGNBOFKH/component_KSEQOEET/auto/%_png.h: ../../../../Source/icons_png/%.png
	../../../Components_ZFTMQEHP/Component_UIGKBCCK/Config_HZEMYJPW/bin2c $< $@
	
build: $(TARGET)  

install:	build
	install -s $(TARGET) $(prefix)/bin
	
clean:
	rm -f $(TARGET) *.o .depend

rebuild: clean build

run:
	./$(TARGET)

debug:
	ddd ./$(TARGET)

$(TARGET):	.depend $(OBJS) $(APILIBDIR)/lib$(APILIB).a
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(ICONAUTO) $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
