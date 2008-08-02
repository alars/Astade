#!/bin/bash -e

cd Model
echo "**********************************"
echo "	Trace2UML"
echo "**********************************"
make -j 2 -C Components_LGPLTGDP/Component_TYWOOIDA/Config_MMRNSTXM/ TARGET=Trace2UML $1
echo "**********************************"
echo "	instrument"
echo "**********************************"
make -j 2 -C Components_LGPLTGDP/Component_instrument/Config_Linux/ TARGET=instrument $1
