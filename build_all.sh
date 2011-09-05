#!/bin/bash -e

cd Model
echo "**********************************"
echo "	bin2c"
echo "**********************************"
make -j 2 -C Components_Helper_components/Component_bin2c/Config_Linux/ TARGET=bin2c $1
echo "**********************************"
echo "	Astade API"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_AstadeAPI/Config_Linux_StatLib/ TARGET=AstadeAPI $1
echo "**********************************"
echo "	AstadeGraphLib"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_AstadeGraphLib/Config_Linux_Statlib/ TARGET=AstadeGraphLib $1
echo "**********************************"
echo "	TraceLib"
echo "**********************************"
make -j 2 -C Components_AstadeFramework/Component_TraceLib/Config_Linux_StatLib/ TARGET=TraceLib $1
echo "**********************************"
echo "	AstadeGenerate"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_AstadeGenerate/Config_Linux_Release/ TARGET=AstadeGenerate $1
echo "**********************************"
echo "	CGenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CGenerator/Config_Linux_Debug/ TARGET=CGenerator $1
echo "**********************************"
echo "	CppGenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CppGenerator/Config_PPWOWKVA/ TARGET=CppGenerator $1
echo "**********************************"
echo "	StateChartCoder"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_StateChartCoder/Config_Linux_Debug/ TARGET=StateChartCoder $1
echo "**********************************"
echo "	StateChartCoderC"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_StateChartCoderC/Config_Linux_Debug/ TARGET=StateChartCoderC $1
echo "**********************************"
echo "	StateChartCoderCdSys"
echo "**********************************"
make -j 2 -C Components_Specials/Component_StateChartCoderCdSys/Config_LinuxConfig/ TARGET=StateChartCoderCdSys $1
echo "**********************************"
echo "	StateChartCoderVSM"
echo "**********************************"
make -j 2 -C Components_Specials/Component_StateChartCoderVSM/Config_Linux_Debug/ TARGET=StateChartCoderVSM $1
echo "**********************************"
echo "	StateChartCoderACF"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_StateChartCoderACF/Config_Linux_Debug/ TARGET=StateChartCoderACF $1
echo "**********************************"
echo "	StateChartCoderACF++"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_StateChartCoderACF++/Config_Linux_Debug/ TARGET=StateChartCoderACF++ $1
echo "**********************************"
echo "	StateChartCoderWx"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_StateChartCoderWx/Config_Linux_Debug/ TARGET=StateChartCoderWx $1
echo "**********************************"
echo "	Astade"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/component_KSEQOEET/config_TLQNHUAH/ TARGET=Astade $1
echo "**********************************"
echo "	ResourceEdit"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_BZBVDSZR/Config_SHHQELQC/ TARGET=ResourceEdit $1
echo "**********************************"
echo "	CSDgenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CSDgenerator/Config_Linux_Debug/ TARGET=CSDgenerator $1
echo "**********************************"
echo "	OMDgenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_OMDgenerator/Config_Linux_Debug/ TARGET=OMDgenerator $1
echo "**********************************"
echo "	StateChartDrawer"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_StateChartDrawer/Config_Linux_Debug/ TARGET=StateChartDrawer $1
echo "**********************************"
echo "	AstadeDraw"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_GZQBNSVE/Config_EKOJVASH/ TARGET=AstadeDraw $1
echo "**********************************"
echo "	Trace2UML"
echo "**********************************"
make -j 2 -C Components_Trace2UML_components/Component_Trace2UML/Config_Linux_Debug/ TARGET=Trace2UML $1
echo "**********************************"
echo "	instrument"
echo "**********************************"
make -j 2 -C Components_Trace2UML_components/Component_instrument/Config_Linux/ TARGET=instrument $1
echo "**********************************"
echo "	CodeEdit"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_NTATHHNC/Config_LGBJUMPF/  TARGET=CodeEdit $1
