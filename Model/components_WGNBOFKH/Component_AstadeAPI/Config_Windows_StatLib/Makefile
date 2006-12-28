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

# ******* Dies evtl ändern **************************
TARGET_ARCH := i586-pc-mingw32
TARGET_GUI := msw
#DEBUG := 1
# ***************************************************

# ******* Ab hier nur für "Experten"*****************
# wxWidgets version
# WXVER	:= 26
# RWX_VER := 2.8 # this should be set as an environment variable
# RWX_PATH := .. #  this should be set as an environment variable

ifdef DEBUG
CXXFLAGS += -g
WXBUILD = debug
WXBUILD_X = d
else
LDFLAGS	+= -Wl,-s
WXBUILD = release
# WXBUILD_X =
endif

LIBDIR  := $(RWX_PATH)/lib

# include path (can be overridden on the command line)
INCLUDE	?= -I../manual
INCLUDE	+= -I../../../../Source/Icons
INCLUDE += -I$(RWX_PATH)/include/wx-$(RWX_VER) -I$(LIBDIR)/wx/include/$(TARGET_ARCH)-$(TARGET_GUI)-ansi-$(WXBUILD)-static-$(RWX_VER)

# librarian
AR	= ar

# compiler settings
CXXFLAGS += $(INCLUDE) -Wall -fstrict-aliasing -D__GNUWIN32__ -D__WXMSW__

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

all:	lib$(TARGET).a

clean:
	rm -f lib$(TARGET).a *.o .depend

lib$(TARGET).a:	.depend $(OBJS)
	$(AR) -rs $@ $(OBJS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
