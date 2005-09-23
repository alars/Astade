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

SOURCES	:= $(wildcard *.cpp)
HEADERS	:= $(wildcard *.h)
OBJS	:= $(SOURCES:.cpp=.o)

CXXFLAGS:= $(shell wx-config --cflags)
LDFLAGS	:= $(shell wx-config --libs)

ifdef DEBUG
CXXFLAGS+= -g
else
LDFLAGS	+= -Wl,-s
endif

all:	$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS) .depend

$(TARGET):	.depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	../Makefile.inc Makefile $(SOURCES) $(HEADERS)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
