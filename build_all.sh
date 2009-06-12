#!/bin/bash -e

cd Model
echo "**********************************"
echo "	bin2c"
echo "**********************************"
make -j 2 -C Components_ZFTMQEHP/Component_UIGKBCCK/Config_HZEMYJPW/ TARGET=bin2c $1
echo "**********************************"
echo "	Astade API"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_AstadeAPI/Config_Linux_StatLib/ TARGET=AstadeAPI $1
echo "**********************************"
echo "	AstadeGraphLib"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_CDFBZLFN/Config_DEHIXAZF/ TARGET=AstadeGraphLib $1
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
echo "	OMDgenerator"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_OMDgenerator/Config_NDLLNZZZ/ TARGET=OMDgenerator $1
echo "**********************************"
echo "	StateChartDrawer"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_EIFKVZMS/Config_NMHWSCLU/ TARGET=StateChartDrawer $1
echo "**********************************"
echo "	AstadeDraw"
echo "**********************************"
make -j 2 -C components_WGNBOFKH/Component_GZQBNSVE/Config_EKOJVASH/ TARGET=AstadeDraw $1
echo "**********************************"
echo "	Trace2UML"
echo "**********************************"
make -j 2 -C Components_LGPLTGDP/Component_TYWOOIDA/Config_MMRNSTXM/ TARGET=Trace2UML $1
echo "**********************************"
echo "	instrument"
echo "**********************************"
make -j 2 -C Components_LGPLTGDP/Component_instrument/Config_Linux/ TARGET=instrument $1
