@echo off
pushd .\Model\components_WGNBOFKH\Component_AstadeAPI\Config_ZMSNZKTV\
echo **********************************
echo Building Astade API
echo **********************************
make %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\components_WGNBOFKH\Component_BZBVDSZR\Windows_Rea\
echo **********************************
echo Building ResourceEdit
echo **********************************
make TARGET=ResourceEdit %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\components_WGNBOFKH\Component_CppGenerator\Config_CPGULUJR\
echo **********************************
echo Building CppGenerator
echo **********************************
make TARGET=CppGenerator %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\components_WGNBOFKH\Component_EIFKVZMS\Windows_Rea\
echo **********************************
echo Building StateChartDrawer
echo **********************************
make TARGET=StateChartDrawer %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\components_WGNBOFKH\Component_IXHOAQJM\Windows_Rea\
echo **********************************
echo Building UseCaseEdit
echo **********************************
make TARGET=UseCaseEdit %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\components_WGNBOFKH\component_KSEQOEET\Config_LXNVUSPP\
echo **********************************
echo Building Astade
echo **********************************
make TARGET=Astade %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\components_WGNBOFKH\Component_OMDgenerator\Windows_Rea\
echo **********************************
echo Building OMDgenerator
echo **********************************
make TARGET=OMDgenerator %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\components_WGNBOFKH\Component_RAVGAUPS\Config_PATMRBOG\
echo **********************************
echo Building StateChartCoder
echo **********************************
make TARGET=StateChartCoder %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\components_WGNBOFKH\Component_XZAWFDAN\Config_OPEOVEFK\
echo **********************************
echo Building AstadeGenerate
echo **********************************
make TARGET=AstadeGenerate %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\components_WGNBOFKH\CppGenerator\Windows_REA
echo **********************************
echo Building CGenerator
echo **********************************
make TARGET=CGenerator %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\components_WGNBOFKH\Component_YIIYAPSY\Windows_Rea\
echo **********************************
echo Building ActivityChartDrawer
echo **********************************
make TARGET=ActivityChartDrawer %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\Components_ZFTMQEHP\Component_RIXFSVSY\Config_NWJYUSSR\
echo **********************************
echo Building WindowsInstallHelper
echo **********************************
make TARGET=WindowsInstallHelper %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\Components_ZLRQZKQB\Component_DJLKKOUQ\Config_DKQBNWAT\
echo **********************************
echo Building StateChartCoderVSM
echo **********************************
make TARGET=StateChartCoderVSM %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\Components_ZLRQZKQB\Component_LUAJBDMB\Config_UDUMBDGY\
echo **********************************
echo Building StateChartCoderWx
echo **********************************
make TARGET=StateChartCoderWx %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\Components_ZLRQZKQB\Component_StateChartCoderCdSys\Config_WEYFLKNX\
echo **********************************
echo Building StateChartCoderCdSys
echo **********************************
make TARGET=StateChartCoderCdSys %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
pushd .\Model\components_WGNBOFKH\Component_FOGYFECV\Windows_REA
echo **********************************
echo Building StateChartCoderC
echo **********************************
make TARGET=StateChartCoderC %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
popd
echo **********************************
echo Building Installer Executable
echo **********************************
call iscc Astade_REA.iss
@if %errorlevel% NEQ 0 goto ERROR
@goto END
:ERROR_MAKE
echo ##################################
@echo MAKE failed failed
@goto END
:ERROR
echo ##################################
@echo Building installer failed
:END
popd