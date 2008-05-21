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

#TARGET_ARCH :=
#TARGET_TOOLKIT  := dfb
#TARGET_UNIV := yes
#TARGET_STATIC := no
#DEBUG := 1

# wxWidgets version
# RWX_VER := 2.8 # this should be set as an environment variable
# RWX_PATH := .. #  this should be set as an environment variable

# ***************************************************

ifdef DEBUG
	CXXFLAGS := -ggdb3 -mapcs-frame -O0
	TARGET_DEBUG := no
else
	CXXFLAGS := -D _TRACE_ -DNDEBUG -O2
	LDFLAGS	:= -Wl,-s
	TARGET_DEBUG := no
endif

INCLUDE	+= -I../auto -I../manual

# compiler settings
CXXFLAGS += $(INCLUDE) -Wall -Werror -fstrict-aliasing


# linker settings
LDFLAGS	+= -L../manual/

# find sources and headers
SOURCES	:= $(wildcard *.cpp ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard *.h ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<


build: $(TARGET)

clean:
	rm -f $(TARGET) *.o .depend

rebuild:	clean build

$(TARGET): .depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
