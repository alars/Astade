MCU = atmega128
CXX = avr-gcc

# include path
INCLUDE	:= -I../manual -I../auto

# compiler settings
CXXFLAGS:= $(INCLUDE) -mmcu=$(MCU) -gdwarf-2 -Wall -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
LDFLAGS	:= -mmcu=$(MCU) -Wl,-s

TRACE_LIST :=$(addsuffix .o,$(TRACECLASSES))

## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.c ../manual/*.c)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.c=.o))

%.o:	../auto/%.c
	$(CXX) $(CXXFLAGS) $(if $(findstring $(notdir $@),$(TRACE_LIST)),-D"_TRACE_" -include ACF_Trace.h ,) -c -o $@ $<

%.o:	../manual/%.c
	$(CXX) $(CXXFLAGS) $(if $(findstring $(notdir $@),$(TRACE_LIST)),-D"_TRACE_" -include ACF_Trace.h ,) -c -o $@ $<

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

build:	$(TARGET).hex

program:	$(TARGET)
	avrdude -c stk500v2 -p m128 -P /dev/ttyACM0 -U $(TARGET).hex

clean:
	rm -f $(TARGET) *.o .depend

rebuild:	clean build

$(TARGET):	.depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CXXFLAGS) $(SOURCES) >$@

-include .depend
