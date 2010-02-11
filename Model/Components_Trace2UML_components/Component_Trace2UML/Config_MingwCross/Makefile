CXX := i586-mingw32msvc-g++
WXCONFIG := /usr/local/i586-mingw32/bin/wx-config

LDFLAGS	:= -Wl,-s

INCLUDE	:= -I../manual

# check make target
$(if $(TARGET),,$(error Variable TARGET not defined))

# compiler settings
CXXFLAGS += `$(WXCONFIG) --cxxflags`
CXXFLAGS += $(INCLUDE) -Wall -fno-strict-aliasing

# linker settings
LDFLAGS	+= `$(WXCONFIG) --libs`

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

build:	$(TARGET).exe

clean:
	rm -f $(TARGET).exe *.o .depend

rebuild:	clean build

$(TARGET).res: ../manual/$(TARGET).rc
	i586-mingw32msvc-windres -i ../manual/$(TARGET).rc --input-format=rc -o $(TARGET).res -O coff --include-dir ../manual --include-dir $(RWX_PATH)/include/wx-$(RWX_VER)

$(TARGET).exe:	.depend $(TARGET).res $(OBJS)
	$(CXX) -o $@ $(OBJS) $(TARGET).res $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
