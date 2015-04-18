#DEBUG := 1

# ***************************************************

ifdef DEBUG
	CXXFLAGS := -g
	LDFLAGS  :=
else
	CXXFLAGS := -O2
	LDFLAGS  := -Wl,-s
endif

TARGET ?= testrunner

# include path
INCLUDE	:= -I../manual -I../auto

# compiler settings
CXXFLAGS += $(INCLUDE) -Wall
LDFLAGS  += -lpthread

TRACE_LIST :=$(addsuffix .o,$(TRACECLASSES))

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(if $(findstring $(notdir $@),$(TRACE_LIST)),-D_TRACE_ -include Trace2UML.h,) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(if $(findstring $(notdir $@),$(TRACE_LIST)),-D_TRACE_ -include Trace2UML.h,) -c -o $@ $<

build:	$(TARGET)

install:	build
	install -s $(TARGET) $(prefix)/bin

clean:
	rm -f $(TARGET) *.o .depend

run:	$(TARGET)
	./$(TARGET) -b -v -s test.txt
#	./$(TARGET) -s test.txt

rebuild:	clean build

$(TARGET):	.depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
