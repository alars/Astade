#!/bin/bash -e

CPUS=2

cd Model
echo "**********************************"
echo "	bin2c"
echo "**********************************"
make -j ${CPUS} -C Components_Helper_components/Component_bin2c/Config_Linux/ TARGET=bin2c $1
echo "**********************************"
echo "	Astade API"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_AstadeAPI/Config_Linux_StatLib/ TARGET=AstadeAPI $1
echo "**********************************"
echo "	AstadeGraphLib"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_AstadeGraphLib/Config_Linux_StatLib/ TARGET=AstadeGraphLib $1
echo "**********************************"
echo "	TraceLib"
echo "**********************************"
make -j ${CPUS} -C Components_AstadeFramework/Component_TraceLib/Config_Linux_StatLib/ TARGET=TraceLib $1
echo "**********************************"
echo "	AstadeGenerate"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_AstadeGenerate/Config_Linux_Release/ TARGET=AstadeGenerate $1
echo "**********************************"
echo "	CGenerator"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_CGenerator/Config_Linux_Debug/ TARGET=CGenerator $1
echo "**********************************"
echo "	CppGenerator"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_CppGenerator/Config_Linux_Debug/ TARGET=CppGenerator $1
echo "**********************************"
echo "	StateChartCoder"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_StateChartCoder/Config_Linux_Debug/ TARGET=StateChartCoder $1
echo "**********************************"
echo "	StateChartCoderC"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_StateChartCoderC/Config_Linux_Debug/ TARGET=StateChartCoderC $1
echo "**********************************"
echo "	StateChartCoderCdSys"
echo "**********************************"
make -j ${CPUS} -C Components_Specials/Component_StateChartCoderCdSys/Config_LinuxConfig/ TARGET=StateChartCoderCdSys $1
echo "**********************************"
echo "	StateChartCoderVSM"
echo "**********************************"
make -j ${CPUS} -C Components_Specials/Component_StateChartCoderVSM/Config_Linux_Debug/ TARGET=StateChartCoderVSM $1
echo "**********************************"
echo "	StateChartCoderACF"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_StateChartCoderACF/Config_Linux_Debug/ TARGET=StateChartCoderACF $1
echo "**********************************"
echo "	StateChartCoderACF++"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_StateChartCoderACF++/Config_Linux_Debug/ TARGET=StateChartCoderACF++ $1
echo "**********************************"
echo "	StateChartCoderQt"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_StateChartCoderQt/Config_Linux_Debug/ TARGET=StateChartCoderQt $1
echo "**********************************"
echo "	StateChartCoderWx"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_StateChartCoderWx/Config_Linux_Debug/ TARGET=StateChartCoderWx $1
echo "**********************************"
echo "	Astade"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_Astade/Config_Linux_Debug/ TARGET=Astade $1
echo "**********************************"
echo "	ResourceEdit"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_ResourceEdit/Config_Linux_Debug/ TARGET=ResourceEdit $1
echo "**********************************"
echo "	CSDgenerator"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_CSDgenerator/Config_Linux_Debug/ TARGET=CSDgenerator $1
echo "**********************************"
echo "	OMDgenerator"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_OMDgenerator/Config_Linux_Debug/ TARGET=OMDgenerator $1
echo "**********************************"
echo "	StateChartDrawer"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_StateChartDrawer/Config_Linux_Debug/ TARGET=StateChartDrawer $1
echo "**********************************"
echo "	AstadeDraw"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_AstadeDraw/Config_Linux_Debug/ TARGET=AstadeDraw $1
echo "**********************************"
echo "	Trace2UML"
echo "**********************************"
make -j ${CPUS} -C Components_Trace2UML_components/Component_Trace2UML/Config_Linux_Debug/ TARGET=Trace2UML $1
echo "**********************************"
echo "	instrument"
echo "**********************************"
make -j ${CPUS} -C Components_Trace2UML_components/Component_instrument/Config_Linux/ TARGET=instrument $1
echo "**********************************"
echo "	testrunner"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_testrunner/Config_Linux/ TARGET=testrunner $1
echo "**********************************"
echo "	CodeEdit"
echo "**********************************"
make -j ${CPUS} -C Components_Astade_components/Component_CodeEdit/Config_Linux_Debug/  TARGET=CodeEdit $1
