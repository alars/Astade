######################################################################
# Project file by Stefan Eilers
######################################################################
TEMPLATE	+= app
CONFIG		+= qt warn_on debug
DESTDIR         = ./
HEADERS         = $$system(ls ../auto/*.h)
HEADERS         += $$system(ls ../manual/*.h)
SOURCES         = $$system(ls ../auto/*.cpp)
SOURCES         += $$system(ls ../manual/*.cpp)
INTERFACES      =
TARGET          = $$(TARGET)

# Directories
