#!/bin/bash -e

# ./configure --prefix=/usr/local/i586-mingw32 --host=i586-mingw32msvc --build=i686-linux --disable-shared

cd Model
echo "**********************************"
echo "	bin2c"
echo "**********************************"
make -j 2 -C Components_Helper_components/Component_bin2c/Config_Linux/ TARGET=bin2c $1
make -j 2 -C Components_Helper_components/Component_bin2c/Config_MingwCross/ TARGET=bin2c $1
echo "**********************************"
echo "	Astade API"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_AstadeAPI/Config_MingwCross/ TARGET=AstadeAPI $1
echo "**********************************"
echo "	AstadeGraphLib"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_AstadeGraphLib/Config_MingwCross/ TARGET=AstadeGraphLib $1
echo "**********************************"
echo "	TraceLib"
echo "**********************************"
make -j 2 -C Components_AstadeFramework/Component_TraceLib/Config_MingwCross/ TARGET=TraceLib $1
echo "**********************************"
echo "	AstadeGenerate"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_AstadeGenerate/Config_MingwCross/ TARGET=AstadeGenerate $1
echo "**********************************"
echo "	CGenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CGenerator/Config_MingwCross/ TARGET=CGenerator $1
echo "**********************************"
echo "	CppGenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CppGenerator/Config_MingwCross/ TARGET=CppGenerator $1
echo "**********************************"
echo "	StateChartCoder"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_StateChartCoder/Config_MingwCross/ TARGET=StateChartCoder $1
echo "**********************************"
echo "	StateChartCoderC"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_StateChartCoderC/Config_MingwCross/ TARGET=StateChartCoderC $1
echo "**********************************"
echo "	StateChartCoderVSM"
echo "**********************************"
make -j 2 -C Components_Specials/Component_StateChartCoderVSM/Config_MingwCross/ TARGET=StateChartCoderVSM $1
echo "**********************************"
echo "	StateChartCoderACF"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_StateChartCoderACF/Config_MingwCross/ TARGET=StateChartCoderACF $1
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
make -j 2 -C components_WGNBOFKH/Component_Astade/Config_MingwCross/ TARGET=Astade $1
echo "**********************************"
echo "	ResourceEdit"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_ResourceEdit/Config_MingwCross/ TARGET=ResourceEdit $1
echo "**********************************"
echo "	CSDgenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CSDgenerator/Config_MingwCross/ TARGET=CSDgenerator $1
echo "**********************************"
echo "	OMDgenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_OMDgenerator/Config_MingwCross/ TARGET=OMDgenerator $1
echo "**********************************"
echo "	StateChartDrawer"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_StateChartDrawer/Config_MingwCross/ TARGET=StateChartDrawer $1
echo "**********************************"
echo "	AstadeDraw"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_AstadeDraw/Config_MingwCross/ TARGET=AstadeDraw $1
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
make -j 2 -C components_WGNBOFKH/Component_CodeEdit/Config_MingwCross/ TARGET=CodeEdit $1
echo "**********************************"
echo "	WindowsInstallHelper"
echo "**********************************"
make -j 2 -C Components_Helper_components/Component_WindowsInstallHelper/Config_MingwCross/ TARGET=WindowsInstallHelper $1

