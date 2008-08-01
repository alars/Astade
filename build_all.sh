#!/bin/bash
pushd ./Model/components_WGNBOFKH/Component_AstadeAPI/Config_Linux_StatLib/
echo **********************************
echo Building Astade API
echo **********************************
make $1 
popd
pushd ./Model/components_WGNBOFKH/Component_BZBVDSZR/Linux_Release_DynApi
echo **********************************
echo Building ResourceEdit
echo **********************************
make TARGET=ResourceEdit $1 
popd
pushd ./Model/components_WGNBOFKH/Component_CppGenerator/Config_PWEPCPEL
echo **********************************
echo Building CppGenerator
echo **********************************
make TARGET=CppGenerator $1 
popd
pushd ./Model/components_WGNBOFKH/Component_EIFKVZMS/Linux_Release_DynApi
echo **********************************
echo Building StateChartDrawer
echo **********************************
make TARGET=StateChartDrawer $1 
popd
pushd ./Model/components_WGNBOFKH/Component_IXHOAQJM/Config_JQTGOPLR
echo **********************************
echo Building UseCaseEdit
echo **********************************
make TARGET=UseCaseEdit $1 
popd
pushd ./Model/components_WGNBOFKH/component_KSEQOEET/Config_WEECFNIW
echo **********************************
echo Building Astade
echo **********************************
make TARGET=Astade $1 
popd
pushd ./Model/components_WGNBOFKH/Component_OMDgenerator/Linux_Release_DynApi
echo **********************************
echo Building OMDgenerator
echo **********************************
make TARGET=OMDgenerator $1 
popd
pushd ./Model/components_WGNBOFKH/Component_RAVGAUPS/Linux_Release_DynApi
echo **********************************
echo Building StateChartCoder
echo **********************************
make TARGET=StateChartCoder $1 
popd
pushd ./Model/components_WGNBOFKH/Component_XZAWFDAN/Config_ZUJGZNUN
echo **********************************
echo Building AstadeGenerate
echo **********************************
make TARGET=AstadeGenerate $1 
popd
pushd ./Model/components_WGNBOFKH/Component_YIIYAPSY/Config_Linux_Debug
echo **********************************
echo Building ActivityChartDrawer
echo **********************************
make TARGET=ActivityChartDrawer $1 
popd
#pushd ./Model/Components_ZFTMQEHP/Component_RIXFSVSY/Config_NWJYUSSR/
#echo **********************************
#echo Building WindowsInstallHelper
#echo **********************************
#make TARGET=WindowsInstallHelper $1 
#popd
pushd ./Model/Components_ZLRQZKQB/Component_DJLKKOUQ/Config_QRNJXIYX
echo **********************************
echo Building StateChartCoderVSM
echo **********************************
make TARGET=StateChartCoderVSM $1 
popd
pushd ./Model/Components_ZLRQZKQB/Component_LUAJBDMB/Config_FMVDEHJG
echo **********************************
echo Building StateChartCoderWx
echo **********************************
make TARGET=StateChartCoderWx $1 
popd
pushd ./Model/Components_ZLRQZKQB/Component_StateChartCoderCdSys/Config_LinuxConfig
echo **********************************
echo Building StateChartCoderCdSys
echo **********************************
make TARGET=StateChartCoderCdSys $1 
popd
