#
# (C) Copyright 2005 Anders Larsen <al@alarsen.net>
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

# check make target
$(if $(TARGET),,$(error Variable TARGET not defined))

# Astade API
APIDIR	:= ../../../components_WGNBOFKH/Component_AstadeAPI
APILIBDIR := $(APIDIR)/Config_Linux_StatLib
APILIB	:= AstadeAPI

# include path
INCLUDE	+= -I../auto -I../manual
INCLUDE	+= -I$(APIDIR)/auto -I$(APIDIR)/manual

# compiler settings
CXXFLAGS:= $(INCLUDE) $(shell wx-config --cxxflags) -Wall
LDFLAGS	:= $(shell wx-config --libs)
LDFLAGS	+= -L$(APILIBDIR) -l$(APILIB)

ifdef DEBUG
CXXFLAGS+= -g
else
CXXFLAGS+= -O2
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

wxgladegen: ../manual/layout.wxg
	wxglade -g C++ -o ../manual $<

clean:
	rm -f $(TARGET) *.o .depend

rebuild:	clean build

run:
	./$(TARGET)

$(TARGET):	.depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
