@echo off
cd Model
echo **********************************
echo Building bin2c
echo **********************************
make -C Components_ZFTMQEHP/Component_UIGKBCCK/Config_HFQMMURT/ TARGET=bin2c %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building Astade API
echo **********************************
make -C components_WGNBOFKH\Component_AstadeAPI\Config_ZMSNZKTV\ TARGET=AstadeAPI %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building AstadeGraphLib
echo **********************************
make -C components_WGNBOFKH\Component_CDFBZLFN\Config_NWPHOJLA\ TARGET=AstadeGraphLib %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building TraceLib
echo **********************************
make -C Components_AstadeFramework\Component_TraceLib\Config_Windows_StatLib\ TARGET=TraceLib %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building AstadeGenerate
echo **********************************
make -C components_WGNBOFKH\Component_XZAWFDAN\Config_OPEOVEFK\ TARGET=AstadeGenerate %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building CGenerator
echo **********************************
make -C components_WGNBOFKH\Component_CGenerator\Windows_REA\ TARGET=CGenerator %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building CppGenerator
echo **********************************
make -C components_WGNBOFKH\Component_CppGenerator\Config_CPGULUJR\ TARGET=CppGenerator %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building StateChartCoder
echo **********************************
make -C components_WGNBOFKH\Component_RAVGAUPS\Config_PATMRBOG\ TARGET=StateChartCoder %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building StateChartCoderC
echo **********************************
make -C components_WGNBOFKH\Component_FOGYFECV\Windows_REA\ TARGET=StateChartCoderC %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building StateChartCoderVSM
echo **********************************
make -C Components_ZLRQZKQB\Component_DJLKKOUQ\Config_DKQBNWAT\ TARGET=StateChartCoderVSM %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building StateChartCoderWx
echo **********************************
make -C Components_ZLRQZKQB\Component_LUAJBDMB\Config_UDUMBDGY\ TARGET=StateChartCoderWx %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building Astade
echo **********************************
make -C components_WGNBOFKH\component_KSEQOEET\Config_LXNVUSPP\ TARGET=Astade %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building ResourceEdit
echo **********************************
make -C components_WGNBOFKH\Component_BZBVDSZR\Windows_Rea\ TARGET=ResourceEdit %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building OMDgenerator
echo **********************************
make -C components_WGNBOFKH\Component_OMDgenerator\Windows_Rea\ TARGET=OMDgenerator %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building StateChartDrawer
echo **********************************
make -C components_WGNBOFKH\Component_EIFKVZMS\Windows_Rea\ TARGET=StateChartDrawer %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building AstadeDraw
echo **********************************
make -C components_WGNBOFKH\Component_GZQBNSVE\Config_CLKAOZUD\ TARGET=AstadeDraw %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building Trace2UML
echo **********************************
make -C Components_LGPLTGDP\Component_TYWOOIDA\Config_DEJDYUKJ\ TARGET=Trace2UML %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building instrument
echo **********************************
make -C Components_LGPLTGDP\Component_instrument\Config_Windows\ TARGET=instrument %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building WindowsInstallHelper
echo **********************************
make -C Components_ZFTMQEHP\Component_RIXFSVSY\Config_NWJYUSSR\ TARGET=WindowsInstallHelper %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building Help-File
echo **********************************
cd ..
call mkhelpzip.bat
echo **********************************
echo Building Installer Executable
echo **********************************
call iscc Astade.iss
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
