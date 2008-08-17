INCLUDEPATH += $$PWD

HEADERS += $$PWD/ModelPropertyKeys.h \
           $$PWD/AstadeDataModel.h \
           $$PWD/AstadeDataModelPrivate.h \
           $$PWD/IconProvider.h \
           $$PWD/ProxyModel.h
                
SOURCES += $$PWD/AstadeDataModel.cpp \
           $$PWD/AstadeDataModelPrivate.cpp \
           $$PWD/IconProvider.cpp \
           $$PWD/ProxyModel.cpp

RESOURCES += $$PWD/icons/icons.qrc