#!/bin/bash -e

cd Model
echo "**********************************"
echo "	Astade API"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_AstadeAPI/Config_Linux_StatLib/ TARGET=AstadeAPI $1
echo "**********************************"
echo "	TraceLib"
echo "**********************************"
make -j 2 -C Components_AstadeFramework/Component_TraceLib/Config_Linux_StatLib/ TARGET=TraceLib $1
echo "**********************************"
echo "	AstadeGenerate"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_XZAWFDAN/Config_ZUJGZNUN/ TARGET=AstadeGenerate $1
echo "**********************************"
echo "	CGenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CGenerator/Linux_Debug/ TARGET=CGenerator $1
echo "**********************************"
echo "	CppGenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CppGenerator/Config_PPWOWKVA/ TARGET=CppGenerator $1
echo "**********************************"
echo "	StateChartCoder"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_RAVGAUPS/Config_AXJYPYCU/ TARGET=StateChartCoder $1
echo "**********************************"
echo "	StateChartCoderC"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_FOGYFECV/Config_HEYGDBJI/ TARGET=StateChartCoderC $1
echo "**********************************"
echo "	StateChartCoderVSM"
echo "**********************************"
make -j 2 -C Components_ZLRQZKQB/Component_DJLKKOUQ/Config_XXQJRNKA/ TARGET=StateChartCoderVSM $1
echo "**********************************"
echo "	StateChartCoderWx"
echo "**********************************"
make -j 2 -C Components_ZLRQZKQB/Component_LUAJBDMB/Config_Linux_Debug/ TARGET=StateChartCoderWx $1
echo "**********************************"
echo "	Astade"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/component_KSEQOEET/config_TLQNHUAH/ TARGET=Astade $1
echo "**********************************"
echo "	ResourceEdit"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_BZBVDSZR/Config_SHHQELQC/ TARGET=ResourceEdit $1
echo "**********************************"
echo "	ActivityChartDrawer"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_YIIYAPSY/Config_Linux_Debug/ TARGET=ActivityChartDrawer $1
echo "**********************************"
echo "	OMDgenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_OMDgenerator/Config_NDLLNZZZ/ TARGET=OMDgenerator $1
echo "**********************************"
echo "	StateChartDrawer"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_EIFKVZMS/Config_NMHWSCLU/ TARGET=StateChartDrawer $1
echo "**********************************"
echo "	UseCaseEdit"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_IXHOAQJM/Config_JQTGOPLR/ TARGET=UseCaseEdit $1
