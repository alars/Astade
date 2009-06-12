#!/bin/bash -e

cd Model
echo "**********************************"
echo "	Astade API"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_AstadeAPI/
echo "**********************************"
echo "	AstadeGraphLib"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_CDFBZLFN/
echo "**********************************"
echo "	TraceLib"
echo "**********************************"
AstadeGenerate -X -c Components_AstadeFramework/Component_TraceLib/
echo "**********************************"
echo "	AstadeGenerate"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_XZAWFDAN/
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
AstadeGenerate -X -c components_WGNBOFKH/Component_RAVGAUPS/
echo "**********************************"
echo "	StateChartCoderC"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_FOGYFECV/
echo "**********************************"
echo "	StateChartCoderVSM"
echo "**********************************"
AstadeGenerate -X -c Components_ZLRQZKQB/Component_DJLKKOUQ/
echo "**********************************"
echo "	StateChartCoderWx"
echo "**********************************"
AstadeGenerate -X -c Components_ZLRQZKQB/Component_LUAJBDMB/
echo "**********************************"
echo "	Astade"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/component_KSEQOEET/
echo "**********************************"
echo "	ResourceEdit"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_BZBVDSZR/
echo "**********************************"
echo "	OMDgenerator"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_OMDgenerator/
echo "**********************************"
echo "	StateChartDrawer"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_EIFKVZMS/
echo "**********************************"
echo "	AstadeDraw"
echo "**********************************"
AstadeGenerate -X -c components_WGNBOFKH/Component_GZQBNSVE/
echo "**********************************"
echo "	Trace2UML"
echo "**********************************"
AstadeGenerate -X -c Components_LGPLTGDP/Component_TYWOOIDA/
