# include path
INCLUDE	:= -I../manual

# check make target
$(if $(TARGET),,$(error Variable TARGET not defined))

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
SOURCES	+= $(wildcard ../auto/*.c ../manual/*.c)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

../$(TARGET).pro: $(SOURCES) $(HEADERS)
	cd ..;qmake -project -recursive -o $(TARGET).pro

../QtMakefile: ../$(TARGET).pro
	cd ..;qmake -o QtMakefile

build:	$(TARGET) 

$(TARGET): ../QtMakefile
	make -f ../QtMakefile