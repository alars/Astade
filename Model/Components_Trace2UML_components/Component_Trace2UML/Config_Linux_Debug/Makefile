#
# (C) Copyright 2006 Anders Larsen <al@alarsen.net>
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

# installation path
prefix	?= ~

# include path
INCLUDE	:= -I../manual

# check make target
$(if $(TARGET),,$(error Variable TARGET not defined))

# compiler settings
WXCONFIG := wx-config
GDK_VERSION := $(if $(shell ${WXCONFIG} --selected-config |grep gtk2),gdk-2.0,gdk-3.0)
CXXFLAGS:= $(INCLUDE) $(shell ${WXCONFIG} --cxxflags) $(shell pkg-config --cflags ${GDK_VERSION}) -Wall -fno-strict-aliasing
LDFLAGS	:= $(shell ${WXCONFIG} --libs) $(shell pkg-config --libs ${GDK_VERSION})

ifdef DEBUG
CXXFLAGS+= -g
else
CXXFLAGS+= -O2
LDFLAGS	+= -Wl,-s
endif

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

build:	$(TARGET)

install:	$(TARGET)
	install -s $(TARGET) $(prefix)/bin

clean:
	rm -f $(TARGET) *.o .depend

rebuild:	clean build

run:
	./$(TARGET)

debug:
	insight ./$(TARGET)

$(TARGET):	.depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
