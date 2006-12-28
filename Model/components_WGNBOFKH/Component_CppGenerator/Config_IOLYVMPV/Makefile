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
INCLUDE += -I$(RWX_PATH)/include/wx-$(RWX_VER) -I$(LIBDIR)/wx/include/$(TARGET_ARCH)-$(TARGET_GUI)-ansi-$(WXBUILD)-static-$(RWX_VER)

# Astade API
APIDIR	:= ../../Component_AstadeAPI
APILIBDIR := $(APIDIR)/Config_Windows_StatLib
APILIB	:= AstadeAPI
INCLUDE	+= -I$(APIDIR)/auto

# compiler settings
CXXFLAGS:= $(INCLUDE) -Wall -fstrict-aliasing -D__GNUWIN32__ -D__WXMSW__

WXLDFLAGS := -mwindows 										\
	-L$(LIBDIR) 											\
	-lwx_$(TARGET_GUI)$(WXBUILD_X)_xrc-$(RWX_VER)-$(TARGET_ARCH)		\
	-lwxexpat$(WXBUILD_X)-$(RWX_VER)-$(TARGET_ARCH)						\
	-lwxjpeg$(WXBUILD_X)-$(RWX_VER)-$(TARGET_ARCH)						\
	-lwxpng$(WXBUILD_X)-$(RWX_VER)-$(TARGET_ARCH)							\
	-lwx_$(TARGET_GUI)$(WXBUILD_X)_adv-$(RWX_VER)-$(TARGET_ARCH) 		\
	-lwx_$(TARGET_GUI)$(WXBUILD_X)_aui-$(RWX_VER)-$(TARGET_ARCH)		\
	-lwx_$(TARGET_GUI)$(WXBUILD_X)_html-$(RWX_VER)-$(TARGET_ARCH)		\
	-lwx_$(TARGET_GUI)$(WXBUILD_X)_richtext-$(RWX_VER)-$(TARGET_ARCH)	\
	-lwx_$(TARGET_GUI)$(WXBUILD_X)_core-$(RWX_VER)-$(TARGET_ARCH)		\
	-lwx_base$(WXBUILD_X)-$(RWX_VER)-$(TARGET_ARCH)

LDFLAGS	:= -L$(APILIBDIR) -l$(APILIB) $(WXLDFLAGS)
# LDFLAGS += -lwxmsw$(WXVER) -lwxmsw$(WXVER)_gl -lwxtiff -lwxjpeg -lwxpng -lwxzlib -lwxregex -lwxexpat
LDFLAGS	+= -lkernel32 -luser32 -lgdi32 -lcomdlg32 -lwinspool -lwinmm -lshell32 -lcomctl32 -lole32 -loleaut32 -luuid -lrpcrt4 -ladvapi32 -lwsock32 -lodbc32 -lopengl32

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

$(TARGET).exe:	.depend $(OBJS) $(APILIBDIR)/lib$(APILIB).a
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >.depend

-include .depend
