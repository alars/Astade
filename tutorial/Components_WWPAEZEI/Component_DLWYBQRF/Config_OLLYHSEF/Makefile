# include path
INCLUDE	:= -I../manual

# compiler settings
CXXFLAGS := $(INCLUDE) -Wall -O2
 
# find sources and headers
SOURCES    := $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS    := $(wildcard ../auto/*.h ../manual/*.h)
 
# objects go into current directory
OBJS    := $(notdir $(SOURCES:.cpp=.o))
 
%.o:    ../auto/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
 
%.o:    ../manual/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
 
build:    $(TARGET)
 
clean:
	rm -f $(TARGET) *.o .depend

rebuild:	clean build

run:
	./$(TARGET)
	
$(TARGET):    .depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)
 
.depend:    Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CXXFLAGS) $(SOURCES) >$@
 
-include .depend
