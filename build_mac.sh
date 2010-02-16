#!/bin/bash -e

cd Model
echo "**********************************"
echo "	bin2c"
echo "**********************************"
make -j 2 -C Components_ZFTMQEHP/Component_UIGKBCCK/Config_XEJMAGUZ/ TARGET=bin2c $1
echo "**********************************"
echo "	Astade API"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_AstadeAPI/Config_Mac_StatLib/ TARGET=AstadeAPI $1
echo "**********************************"
echo "	TraceLib"
echo "**********************************"
#make -j 2 -C Components_AstadeFramework/Component_TraceLib/Config_Mac_StatLib/ TARGET=TraceLib $1
echo "**********************************"
echo "	AstadeGenerate"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_XZAWFDAN/Config_SJSIVLSG/ TARGET=AstadeGenerate $1
echo "**********************************"
echo "	CGenerator"
echo "**********************************"
#make -j 2 -C components_WGNBOFKH/Component_CGenerator/Mac_Debug/ TARGET=CGenerator $1
echo "**********************************"
echo "	CppGenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CppGenerator/Config_WUZEBEMM/ TARGET=CppGenerator $1
echo "**********************************"
echo "	StateChartCoder"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_RAVGAUPS/Config_PCSMCOCP/ TARGET=StateChartCoder $1
echo "**********************************"
echo "	StateChartCoderC"
echo "**********************************"
#make -j 2 -C components_WGNBOFKH/Component_FOGYFECV/Config_HEYGDBJI/ TARGET=StateChartCoderC $1
echo "**********************************"
echo "	StateChartCoderVSM"
echo "**********************************"
#make -j 2 -C Components_ZLRQZKQB/Component_DJLKKOUQ/Config_XXQJRNKA/ TARGET=StateChartCoderVSM $1
echo "**********************************"
echo "	StateChartCoderWx"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_StateChartCoderWx/Config_Mac_Debug/ TARGET=StateChartCoderWx $1
echo "**********************************"
echo "	Astade"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/component_KSEQOEET/Config_HQFQWMIL/ TARGET=Astade $1
echo "**********************************"
echo "	ResourceEdit"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_BZBVDSZR/Config_VXTTQJXA/ TARGET=ResourceEdit $1
echo "**********************************"
echo "	ActivityChartDrawer"
echo "**********************************"
#make -j 2 -C components_WGNBOFKH/Component_YIIYAPSY/Config_Mac_Debug/ TARGET=ActivityChartDrawer $1
echo "**********************************"
echo "	OMDgenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_OMDgenerator/Config_JFKMJNOD/ TARGET=OMDgenerator $1
echo "**********************************"
echo "	StateChartDrawer"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_EIFKVZMS/Config_WIEGKBYW/ TARGET=StateChartDrawer $1
echo "**********************************"
echo "	UseCaseEdit"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_IXHOAQJM/Config_PVQUPIOG/ TARGET=UseCaseEdit $1
echo "**********************************"
echo "	Trace2UML"
echo "**********************************"
make -j 2 -C Components_Trace2UML_components/Component_Trace2UML/Config_Mac_Debug/ TARGET=Trace2UML $1
echo "**********************************"
echo "	instrument"
echo "**********************************"
#make -j 2 -C Components_Trace2UML_components/Component_instrument/Config_Linux/ TARGET=instrument $1
