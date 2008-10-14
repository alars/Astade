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

# include path
INCLUDE	:= -I../manual -I../auto

# check make target
$(if $(TARGET),,$(error Variable TARGET not defined))

# compiler settings
CXXFLAGS:= $(INCLUDE) $(shell wx-config --cxxflags) -Wall -x c
LDFLAGS	:= $(shell wx-config --libs)

ifdef DEBUG
CXXFLAGS+= -g
else
CXXFLAGS+= -O2
LDFLAGS	+= -Wl,-s
endif

CXX = $(CC)

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp ../auto/*.c ../manual/*.c)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS1	:= $(notdir $(SOURCES:%.cpp=%.o))
OBJS	:= $(notdir $(OBJS1:%.c=%.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../auto/%.c
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.c
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

build:	$(TARGET)

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
