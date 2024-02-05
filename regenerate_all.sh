#!/bin/bash -e

VERSION=$(git describe 2> /dev/null | sed "s/^release//" | sed "s/^v//" | sed "s/-\([0-9]*\)-\(g[0-9a-f]*\)/.\1~\2/")

echo "#define AstadeVersion \"${VERSION}\"" > Model/Components_Astade_components/Component_Astade/manual/AstadeVersion.h
echo "#define Trace2UMLVersion \"${VERSION}\"" > Model/Components_Trace2UML_components/Component_Trace2UML/manual/Trace2UMLVersion.h

cd Model
echo "**********************************"
echo "	Astade API"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_AstadeAPI/
echo "**********************************"
echo "	AstadeGraphLib"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_AstadeGraphLib/
echo "**********************************"
echo "	TraceLib"
echo "**********************************"
AstadeGenerate -X -c Components_AstadeFramework/Component_TraceLib/
echo "**********************************"
echo "	AstadeGenerate"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_AstadeGenerate/
echo "**********************************"
echo "	CGenerator"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_CGenerator/
echo "**********************************"
echo "	CppGenerator"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_CppGenerator/
echo "**********************************"
echo "	StateChartCoder"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_StateChartCoder/
echo "**********************************"
echo "	StateChartCoderC"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_StateChartCoderC/
echo "**********************************"
echo "	StateChartCoderVSM"
echo "**********************************"
AstadeGenerate -X -c Components_Specials/Component_StateChartCoderVSM/
echo "**********************************"
echo "	StateChartCoderCdSys"
echo "**********************************"
AstadeGenerate -X -c Components_Specials/Component_StateChartCoderCdSys/
echo "**********************************"
echo "	StateChartCoderACF"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_StateChartCoderACF/
echo "**********************************"
echo "	StateChartCoderACF++"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_StateChartCoderACF++/
echo "**********************************"
echo "	StateChartCoderQt"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_StateChartCoderQt/
echo "**********************************"
echo "	StateChartCoderWx"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_StateChartCoderWx/
echo "**********************************"
echo "	Astade"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_Astade/
echo "**********************************"
echo "	ResourceEdit"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_ResourceEdit/
echo "**********************************"
echo "	CSDgenerator"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_CSDgenerator/
echo "**********************************"
echo "	OMDgenerator"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_OMDgenerator/
echo "**********************************"
echo "	StateChartDrawer"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_StateChartDrawer/
echo "**********************************"
echo "	AstadeDraw"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_AstadeDraw/
echo "**********************************"
echo "	Trace2UML"
echo "**********************************"
AstadeGenerate -X -c Components_Trace2UML_components/Component_Trace2UML/
echo "**********************************"
echo "	CodeEdit"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_CodeEdit/
echo "**********************************"
echo "	ACF"
echo "**********************************"
AstadeGenerate -X -c Components_AstadeFramework/Component_ACF/
echo "**********************************"
echo "	instrument"
echo "**********************************"
AstadeGenerate -X -c Components_Trace2UML_components/Component_instrument/
echo "**********************************"
echo "	testrunner"
echo "**********************************"
AstadeGenerate -X -c Components_Astade_components/Component_testrunner/
