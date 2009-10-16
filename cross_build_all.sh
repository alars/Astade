#!/bin/bash -e

# ./configure --prefix=/usr/local/i586-mingw32 --host=i586-mingw32msvc --build=i686-linux --disable-shared

export CXX=i586-mingw32msvc-g++
export WXCONFIG=/usr/local/i586-mingw32/bin/wx-config


cd Model
echo "**********************************"
echo "	bin2c"
echo "**********************************"
make -j 2 -C Components_ZFTMQEHP/Component_UIGKBCCK/Config_HFQMMURT/ TARGET=bin2c $1
echo "**********************************"
echo "	Astade API"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_AstadeAPI/Config_ZMSNZKTV/ TARGET=AstadeAPI $1
echo "**********************************"
echo "	AstadeGraphLib"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CDFBZLFN/Config_NWPHOJLA/ TARGET=AstadeGraphLib $1
echo "**********************************"
echo "	TraceLib"
echo "**********************************"
make -j 2 -C Components_AstadeFramework/Component_TraceLib/Config_Windows_StatLib/ TARGET=TraceLib $1
echo "**********************************"
echo "	AstadeGenerate"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_XZAWFDAN/Config_OPEOVEFK/ TARGET=AstadeGenerate $1

