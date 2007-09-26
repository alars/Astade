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
TARGET_TOOLKIT  := msw
TARGET_UNIV := no
TARGET_STATIC := yes
TARGET_DEBUG := no
# DEBUG := 1

# wxWidgets version
# RWX_VER := 2.8 # this should be set as an environment variable
RWX_PATH := /wxWidgets-2.8.5/mingw/
# ***************************************************

ifdef DEBUG
	CXXFLAGS := -g
	LDFLAGS	:=
	TARGET_DEBUG := yes
else
	CXXFLAGS :=
	LDFLAGS	:= -Wl,-s
endif

#WXCONFIG := wx-config --prefix=$(RWX_PATH) --host=$(TARGET_ARCH) --toolkit=${TARGET_TOOLKIT} --universal=${TARGET_UNIV} --static=${TARGET_STATIC} --debug=${TARGET_DEBUG}
WXCONFIG := $(RWX_PATH)wx-config --prefix=$(RWX_PATH) --host= --toolkit=msw

# include path
INCLUDE	:= -I../manual
INCLUDE	+= -I../auto
INCLUDE	+= -I../../../../Source/Icons

# Astade API
APIDIR	:= ../../Component_AstadeAPI
APILIBDIR := $(APIDIR)/Config_ZMSNZKTV
APILIB	:= AstadeAPI
INCLUDE	+= -I$(APIDIR)/auto
LDFLAGS	+= -L$(APILIBDIR) -l$(APILIB)


# compiler settings
OCXXFLAGS := $(shell $(WXCONFIG) --cxxflags)
CXXFLAGS += $(patsubst -I/d/%,-Id:/%,$(OCXXFLAGS))

CXXFLAGS += $(INCLUDE) -Wall -fstrict-aliasing

# linker settings
LDFLAGS	+= -Wl,--start-group -lwxmsw28_stc
OLDFLAGS	+= $(shell $(WXCONFIG) --libs) -Wl,--end-group
OOLDFLAGS += $(patsubst -L/d/%,-Ld:/%,$(OLDFLAGS))

LDFLAGS += $(patsubst /d/%,d:/%,$(OOLDFLAGS))

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h $(APIDIR)/auto/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

../../../components_WGNBOFKH/component_KSEQOEET/auto/%_png.h:	../../../../Source/icons_png/%.png
	../../../Components_ZFTMQEHP/Component_UIGKBCCK/Config_HFQMMURT/bin2c $< $@

build:	$(ICONAUTO) $(TARGET).exe

clean:
	rm -f $(TARGET).exe *.o .depend

rebuild: clean build

run:
	$(TARGET).exe jj

debug:
	insight-x86 $(TARGET).exe

$(TARGET).res: ../manual/$(TARGET).rc ../../../../Source/Icons/Astade.ico
	windres.exe -i ../manual/$(TARGET).rc --input-format=rc -o $(TARGET).res -O coff --include-dir ../../../../Source/Icons --include-dir $(RWX_PATH)/include/wx-$(RWX_VER)

$(TARGET).exe: $(TARGET).res $(OBJS) $(APILIBDIR)/lib$(APILIB).a
	$(CXX) -o $@ $(OBJS) $(TARGET).res $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
