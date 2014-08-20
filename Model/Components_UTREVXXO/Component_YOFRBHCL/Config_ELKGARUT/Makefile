#DEBUG := 1

# ***************************************************

ifdef DEBUG
	CXXFLAGS := -g
	LDFLAGS	:=
else
	CXXFLAGS :=
	LDFLAGS	:= -Wl,-s
endif

# include path
INCLUDE	:= -I../manual -I../auto

# compiler settings
CXXFLAGS += $(INCLUDE) -Wall

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

build:	$(TARGET)

install:	build

clean:
	rm -f $(TARGET) *.o .depend

rebuild:	clean build

run: build
	./$(TARGET)

$(TARGET):	.depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
