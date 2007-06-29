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
# DEBUG	:= 1

# wxWidgets version
WXVER	:= 26

# include path
INCLUDE	:= -I../manual
INCLUDE	+= -I../../../../Source/Icons

#This should be different depends on the installation of wxWidgets
#This is for windres.exe
DevCppInclude := F:\Dev-Cpp\include

# Astade API
APIDIR	:= ../../Component_AstadeAPI
APILIBDIR := $(APIDIR)/Config_Windows_StatLib
APILIB	:= AstadeAPI
INCLUDE	+= -I$(APIDIR)/auto

# compiler settings
CXXFLAGS:= $(INCLUDE) -Wall -fstrict-aliasing -D__GNUWIN32__ -D__WXMSW__
LDFLAGS	:= -L$(APILIBDIR) -l$(APILIB)
LDFLAGS	+= -mwindows -lwxmsw$(WXVER) -lwxmsw$(WXVER)_gl -lwxtiff -lwxjpeg -lwxpng -lwxzlib -lwxregex -lwxexpat
LDFLAGS	+= -lkernel32 -luser32 -lgdi32 -lcomdlg32 -lwinspool -lwinmm -lshell32 -lcomctl32 -lole32 -loleaut32 -luuid -lrpcrt4 -ladvapi32 -lwsock32 -lodbc32 -lopengl32

ifdef DEBUG
CXXFLAGS+= -g
else
LDFLAGS	+= -Wl,-s
endif

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

# $(TARGET).res: ../manual/$(TARGET).rc
# 	windres.exe -i ../manual/$(TARGET).rc --input-format=rc -o $(TARGET).res -O coff --include-dir ../../../../Source/Icons --include-dir $(DevCppInclude)


$(TARGET).exe:	.depend $(OBJS) $(APILIBDIR)/lib$(APILIB).a
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
