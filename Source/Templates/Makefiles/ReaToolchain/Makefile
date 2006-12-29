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

TARGET	?= Astade
TARGET_ARCH := i586-pc-mingw32
TARGET_GUI  := msw
TARGET_ENC  := ansi
TARGET_LINK := static
#DEBUG := 1

# wxWidgets version
# RWX_VER := 2.8 # this should be set as an environment variable
# RWX_PATH := .. #  this should be set as an environment variable

# ***************************************************

ifdef DEBUG
	CXXFLAGS := -g
	LDFLAGS	:=
	WXBUILD := debug
else
	CXXFLAGS :=
	LDFLAGS	:= -Wl,-s
	WXBUILD := release
endif

WXCONFIG := $(RWX_PATH)/lib/wx/config/$(TARGET_ARCH)-$(TARGET_GUI)-$(TARGET_ENC)-$(WXBUILD)-$(TARGET_LINK)-$(RWX_VER)

INCLUDE	?= -I../manual

# Astade API
APIDIR	:= ../../Component_AstadeAPI
APILIBDIR := $(APIDIR)/Config_Windows_StatLib
APILIB	:= AstadeAPI
INCLUDE	+= -I$(APIDIR)/auto
LDFLAGS	+= -L$(APILIBDIR) -l$(APILIB)

# compiler settings
CXXFLAGS += `$(WXCONFIG) --prefix=$(RWX_PATH) --cxxflags`
CXXFLAGS += $(INCLUDE) -Wall -fstrict-aliasing

# linker settings
LDFLAGS	+= `$(WXCONFIG) --prefix=$(RWX_PATH) --libs`

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h $(APIDIR)/auto/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

all:	$(TARGET).exe

clean:
	rm -f $(TARGET).exe *.o .depend

$(TARGET).res: ../manual/$(TARGET).rc

	windres.exe -i ../manual/$(TARGET).rc --input-format=rc -o $(TARGET).res -O coff --include-dir ../../../../Source/Icons --include-dir $(RWX_PATH)/include

$(TARGET).exe:	.depend $(TARGET).res $(OBJS) $(APILIBDIR)/lib$(APILIB).a
	$(CXX) -o $@ $(OBJS) $(TARGET).res $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
