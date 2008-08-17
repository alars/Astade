# Settings used by main and subprojects
MOC_DIR     = ./moc
UI_DIR      = ./ui
OBJECTS_DIR = ./obj

CONFIG -= flat

CONFIG += debug 
#useDebugConsole

DEPENDPATH += $$PWD
INCLUDEPATH += $$PWD 

useDebugConsole {
    include( ../basystools/debugconsole/src/src.pri )
}
