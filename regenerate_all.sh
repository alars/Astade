#!/bin/bash -e

cd Model
echo "**********************************"
echo "	Astade API"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_AstadeAPI/
echo "**********************************"
echo "	AstadeGraphLib"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_AstadeGraphLib/
echo "**********************************"
echo "	TraceLib"
echo "**********************************"
AstadeGenerate -X -c Components_AstadeFramework/Component_TraceLib/
echo "**********************************"
echo "	AstadeGenerate"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_AstadeGenerate/
echo "**********************************"
echo "	CGenerator"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_CGenerator/
echo "**********************************"
echo "	CppGenerator"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_CppGenerator/
echo "**********************************"
echo "	StateChartCoder"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_StateChartCoder/
echo "**********************************"
echo "	StateChartCoderC"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_StateChartCoderC/
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
AstadeGenerate -X -c components_WGNBOFKH/Component_StateChartCoderACF/
echo "**********************************"
echo "	StateChartCoderACF++"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_StateChartCoderACF++/
echo "**********************************"
echo "	StateChartCoderWx"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_StateChartCoderWx/
echo "**********************************"
echo "	Astade"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_Astade/
echo "**********************************"
echo "	ResourceEdit"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_ResourceEdit/
echo "**********************************"
echo "	CSDgenerator"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_CSDgenerator/
echo "**********************************"
echo "	OMDgenerator"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_OMDgenerator/
echo "**********************************"
echo "	StateChartDrawer"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_StateChartDrawer/
echo "**********************************"
echo "	AstadeDraw"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_AstadeDraw/
echo "**********************************"
echo "	Trace2UML"
echo "**********************************"
AstadeGenerate -X -c Components_Trace2UML_components/Component_Trace2UML/
echo "**********************************"
echo "	CodeEdit"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_CodeEdit/
echo "**********************************"
echo "	ACF"
echo "**********************************"
AstadeGenerate -X -c Components_AstadeFramework/Component_ACF/
