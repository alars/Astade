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

TARGET_TOOLKIT  := msw
TARGET_UNIV := no
TARGET_STATIC := yes
TARGET_DEBUG := no

TRACE_LIST :=$(addsuffix .o,$(TRACECLASSES))

# DEBUG := 1

ifdef DEBUG
	CXXFLAGS := -g
	LDFLAGS	:=
	TARGET_DEBUG := yes
else
	CXXFLAGS :=
	LDFLAGS	:= -Wl,-s
endif

WXCONFIG := wx-config --prefix=$(RWX_PATH) --toolkit=${TARGET_TOOLKIT} --universal=${TARGET_UNIV} --static=${TARGET_STATIC} --debug=${TARGET_DEBUG} --version=${RWX_VER}

# include path
INCLUDE	+= -I../manual -I../auto
INCLUDE	+= -I../../../../Source/Icons

# librarian
AR	:= ar

# compiler settings
CXXFLAGS += $(shell $(WXCONFIG) --cxxflags)
CXXFLAGS += $(INCLUDE) -Wall

# linker settings
LDFLAGS	+= $(shell $(WXCONFIG) --libs)

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(if $(findstring $(notdir $@),$(TRACE_LIST)),-D"_TRACE_" -include wxTrace2file.h,) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

build:	lib$(TARGET).a

clean:
	rm -f lib$(TARGET).a *.o .depend

rebuild: clean build

lib$(TARGET).a:	.depend $(OBJS)
	$(AR) -rs $@ $(OBJS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
