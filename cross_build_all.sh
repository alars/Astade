#!/bin/bash -e

# ./configure --prefix=/usr/local/i586-mingw32 --host=i586-mingw32msvc --build=i686-linux --disable-shared

cd Model
echo "**********************************"
echo "	bin2c"
echo "**********************************"
make -j 2 -C Components_ZFTMQEHP/Component_UIGKBCCK/Config_HZEMYJPW/ TARGET=bin2c $1
make -j 2 -C Components_ZFTMQEHP/Component_UIGKBCCK/Config_CDBXRNYG/ TARGET=bin2c $1
echo "**********************************"
echo "	Astade API"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_AstadeAPI/Config_AQAHLGFG/ TARGET=AstadeAPI $1
echo "**********************************"
echo "	AstadeGraphLib"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CDFBZLFN/Config_XSIGOWGY/ TARGET=AstadeGraphLib $1
echo "**********************************"
echo "	TraceLib"
echo "**********************************"
make -j 2 -C Components_AstadeFramework/Component_TraceLib/Config_QSRQIPTA/ TARGET=TraceLib $1
echo "**********************************"
echo "	AstadeGenerate"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_XZAWFDAN/Config_MUIULJPX/ TARGET=AstadeGenerate $1
echo "**********************************"
echo "	CGenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CGenerator/Config_RQZURJDX/ TARGET=CGenerator $1
echo "**********************************"
echo "	CppGenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CppGenerator/Config_QDCKBOPV/ TARGET=CppGenerator $1
echo "**********************************"
echo "	StateChartCoder"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_RAVGAUPS/Config_ILIZODGP/ TARGET=StateChartCoder $1
echo "**********************************"
echo "	StateChartCoderC"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_FOGYFECV/Config_JLHBJBHX/ TARGET=StateChartCoderC $1
echo "**********************************"
echo "	StateChartCoderVSM"
echo "**********************************"
make -j 2 -C Components_ZLRQZKQB/Component_DJLKKOUQ/Config_AVMVYCHR/ TARGET=StateChartCoderVSM $1
echo "**********************************"
echo "	StateChartCoderACF"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CBEUPFRX/Config_KEZZGSDO/ TARGET=StateChartCoderACF $1
echo "**********************************"
echo "	StateChartCoderACF++"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_StateChartCoderACF++/Config_MingwCross/ TARGET=StateChartCoderACF++ $1
echo "**********************************"
echo "	StateChartCoderWx"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_StateChartCoderWx/Config_MingwCross/ TARGET=StateChartCoderWx $1
echo "**********************************"
echo "	Astade"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/component_KSEQOEET/Config_KKSMNXBE/ TARGET=Astade $1
echo "**********************************"
echo "	ResourceEdit"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_BZBVDSZR/Config_PYAUPGTA/ TARGET=ResourceEdit $1
echo "**********************************"
echo "	OMDgenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_OMDgenerator/Config_HRNMFIQH/ TARGET=OMDgenerator $1
echo "**********************************"
echo "	StateChartDrawer"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_EIFKVZMS/Config_CLRCZBOI/ TARGET=StateChartDrawer $1
echo "**********************************"
echo "	AstadeDraw"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_GZQBNSVE/Config_QZFNIVMZ/ TARGET=AstadeDraw $1
echo "**********************************"
echo "	Trace2UML"
echo "**********************************"
make -j 2 -C Components_Trace2UML_components/Component_Trace2UML/Config_MingwCross/ TARGET=Trace2UML $1
echo "**********************************"
echo "	instrument"
echo "**********************************"
make -j 2 -C Components_Trace2UML_components/Component_instrument/Config_MingwCross/ TARGET=instrument $1
echo "**********************************"
echo "	CodeEdit"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_NTATHHNC/Config_KGKKVXGF/ TARGET=CodeEdit $1
echo "**********************************"
echo "	WindowsInstallHelper"
echo "**********************************"
make -j 2 -C Components_ZFTMQEHP/Component_RIXFSVSY/Config_AHWQEEPV/ TARGET=WindowsInstallHelper $1

