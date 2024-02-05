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
INCLUDE	:= -I../manual

# check make target
$(if $(TARGET),,$(error Variable TARGET not defined))

# compiler settings
CFLAGS:= $(INCLUDE) $(shell wx-config --cxxflags) -fabi-version=13 -std=gnu++03 -Wall
LDFLAGS	:= $(shell wx-config --libs)

ifdef DEBUG
CFLAGS+= -g
else
CFLAGS+= -O2
LDFLAGS	+= -Wl,-s
endif

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.c ../manual/*.c ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

SOURCES += ../manual/timeout/timeout.c

# objects go into current directory
OBJS	:= $(SOURCES:.cpp=.o)
# $(notdir
OBJS	:= $(OBJS:.c=.o)
# $(notdir 

%.o:	../auto/%.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

build:	$(TARGET)

clean:
	rm -f $(TARGET) *.o .depend
	rm -f $(OBJS)

rebuild:	clean build

run:
	./$(TARGET)

$(TARGET):	.depend $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CC) -MM $(CPPFLAGS) $(CFLAGS) $(SOURCES) >$@

-include .depend
