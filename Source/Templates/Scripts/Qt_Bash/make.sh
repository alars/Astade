#/bin/bash
## Compile script for Qt
## Written by Stefan Eilers
## This script starts qmake first to create a makefile

echo "Params       = "$*
echo "Export       : "$3
echo "Compiling dir: "$2

# Remove QMAKESPEC which may cause qmake to create something
# different files Makefiles
echo "Warning: Remove QMAKESPEC and hope it is a good idea!"
unset QMAKESPEC

export $3
cd $2
CURRENT=`pwd`
echo "Starting qmake in dir "$CURRENT
qmake
make $*
