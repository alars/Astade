#!/bin/bash -e

cd Model
echo "**********************************"
echo "	Trace2UML"
echo "**********************************"
make -j 2 -C Components_Trace2UML_components/Component_Trace2UML/Config_Linux_Debug/ TARGET=Trace2UML $1
echo "**********************************"
echo "	instrument"
echo "**********************************"
make -j 2 -C Components_Trace2UML_components/Component_instrument/Config_Linux/ TARGET=instrument $1
