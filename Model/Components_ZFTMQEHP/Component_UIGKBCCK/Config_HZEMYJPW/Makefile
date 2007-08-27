#TARGET_ARCH := i586-pc-mingw32
#DEBUG := 1

# ***************************************************

ifdef DEBUG
	CXXFLAGS := -g
	LDFLAGS	:=
	TARGET_DEBUG := yes
else
	CXXFLAGS :=
	LDFLAGS	:= -Wl,-s
endif

# include path
INCLUDE	:= -I../manual

# compiler settings
CXXFLAGS += $(INCLUDE) -Wall -fstrict-aliasing

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)
ICONSOURCE	:= $(wildcard ../manual/*.png)

ICONDEST = $(patsubst %.png,%_png.h,$(ICONSOURCE))
ICONAUTO = $(patsubst ../manual%,../../../components_WGNBOFKH/component_KSEQOEET/manual%,$(ICONDEST))

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

../../../components_WGNBOFKH/component_KSEQOEET/manual/%_png.h:	../manual/%.png
	IconGenerate $< $@

iconcreate: $(ICONAUTO) $(TARGET)

build:	$(TARGET)

clean:
	rm -f $(TARGET) *.o .depend

$(TARGET):	.depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
