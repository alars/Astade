######################################################################
# Main project file
######################################################################

TEMPLATE = app
TARGET = AstadeView
DESTDIR = ./bin

win32{
    TARGET_INSTALL_PATH = "C:/Program Files/Astade"
} else {
    TARGET_INSTALL_PATH = $(HOME)/bin
}

target.path += $$TARGET_INSTALL_PATH
INSTALLS += target

# Load common project settings
include ( $$PWD/AstadeView.pri )

# The flag "TESTMODE_" changes the default behavior to provide debugging features.
# debug {
        DEFINES += TESTMODE_
# }

# Input
HEADERS +=  MainWindow.h \
            Globals.h

SOURCES +=  MainWindow.cpp \
            Globals.cpp \
            main.cpp 

FORMS += MainWindow.ui ConfigDialog.ui


# Views
include( $$PWD/views/views.pri )

# Database Model: Implements operations on the Astade Database
include( $$PWD/database_model/database_model.pri )
           
# Element Controller: Implements operations on the database and defines its default appearance in the View.
include ( $$PWD/element_controller/element_controller.pri )

# Model Delegates: Delegates controls the look and feel of a model item.
include ( $$PWD/delegates/delegates.pri )

# Platform specific stuff
include ( $$PWD/platform/platform.pri )
           
FORMS += $$PWD/delegates/FeatureEditor.ui
