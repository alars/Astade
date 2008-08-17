CONFIG += USE_GENERIC_MODE

!USE_GENERIC_MODE:macx {
    # Using special widgets on the mac platform
    INCLUDEPATH += $$PWD/mac/
    HEADERS     += $$PWD/mac/SearchWidget.h
    SOURCES     += $$PWD/mac/SearchWidget.cpp
    
} else {
    # Using generic implementation which will work on all platforms
    INCLUDEPATH += $$PWD/generic/
    HEADERS     += $$PWD/generic/SearchWidget.h
    SOURCES     += $$PWD/generic/SearchWidget.cpp
}

