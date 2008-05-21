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

TARGETNAME := SingleFrame
#TARGET_ARCH :=
#TARGET_GUI := dfbuniv
#TARGET_ENC  := ansi
#TARGET_LINK := # static-
#WXSUFFIX := -bct500
#DEBUG := 1

# wxWidgets version
# RWX_VER := 2.8 # this should be set as an environment variable
# RWX_PATH := .. #  this should be set as an environment variable

# ***************************************************

CXX = g++

ifdef DEBUG
	CXXFLAGS := -ggdb3 -mapcs-frame -O0
	LDFLAGS	:=
	TAGRET_DEBUG := no
else
	CXXFLAGS :=
	LDFLAGS	:= -Wl,-s
	TAGRET_DEBUG := no
endif

# this needs that $(RWX_PATH)/bin is in your path!
WXCONFIG := wx-config --debug=${TAGRET_DEBUG}

INCLUDE	?= -I../auto -I../manual

# compiler settings
CXXFLAGS += $(INCLUDE) -Wall -Werror -fstrict-aliasing -march=armv4t
CXXFLAGS += $(shell $(WXCONFIG) --cxxflags)


# linker settings
LDFLAGS	+= -ldirect -ldirectfb -lfusion
LDFLAGS	+= $(shell $(WXCONFIG) --libs)

# find sources and headers
SOURCES	:= $(wildcard *.cpp ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard *.h ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<


build: $(TARGETNAME)

clean:
	rm -f $(TARGETNAME) *.o .depend

$(TARGETNAME): .depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)
	cp $(TARGETNAME) ../../../files/

install: $(TARGETNAME)
	pscp -pw root $(TARGETNAME) root@192.168.101.38:/usr/bin

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
