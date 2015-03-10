# include path
INCLUDE	:= -I../manual

# check make target
$(if $(TARGET),,$(error Variable TARGET not defined))

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
SOURCES	+= $(wildcard ../auto/*.c ../manual/*.c)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

build:	$(TARGET)

run: build
	./$(TARGET)

clean:
	rm -f *.o $(TARGET) ../$(TARGET).pro ../QtMakefile QtMakefile

../$(TARGET).pro: $(SOURCES) $(HEADERS)
	cd ..;qmake -project -recursive -o $(TARGET).pro

../QtMakefile: ../$(TARGET).pro
	cd ..;qmake -o QtMakefile
	sed -i 's/$(TARGET).pro/..\/$(TARGET).pro/' ../QtMakefile
	sed -i 's/manual\//..\/manual\//' ../QtMakefile
	sed -i 's/auto\//..\/auto\//' ../QtMakefile

$(TARGET): ../QtMakefile
	make -f ../QtMakefile