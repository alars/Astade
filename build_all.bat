@echo off
cd Model
echo **********************************
echo Building bin2c
echo **********************************
make -j 2 -C Components_ZFTMQEHP/Component_UIGKBCCK/Config_HFQMMURT/ TARGET=bin2c %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building Astade API
echo **********************************
make -j 2 -C components_WGNBOFKH\Component_AstadeAPI\Config_ZMSNZKTV\ TARGET=AstadeAPI %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building AstadeGraphLib
echo **********************************
make -j 2 -C components_WGNBOFKH\Component_CDFBZLFN\Config_NWPHOJLA\ TARGET=AstadeGraphLib %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building TraceLib
echo **********************************
make -j 2 -C Components_AstadeFramework\Component_TraceLib\Config_Windows_StatLib\ TARGET=TraceLib %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building AstadeGenerate
echo **********************************
make -j 2 -C components_WGNBOFKH\Component_XZAWFDAN\Config_OPEOVEFK\ TARGET=AstadeGenerate %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building CGenerator
echo **********************************
make -j 2 -C components_WGNBOFKH\Component_CGenerator\Windows_REA\ TARGET=CGenerator %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building CppGenerator
echo **********************************
make -j 2 -C components_WGNBOFKH\Component_CppGenerator\Config_CPGULUJR\ TARGET=CppGenerator %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building StateChartCoder
echo **********************************
make -j 2 -C components_WGNBOFKH\Component_RAVGAUPS\Config_PATMRBOG\ TARGET=StateChartCoder %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building StateChartCoderC
echo **********************************
make -j 2 -C components_WGNBOFKH\Component_FOGYFECV\Windows_REA\ TARGET=StateChartCoderC %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building StateChartCoderVSM
echo **********************************
make -j 2 -C Components_ZLRQZKQB\Component_DJLKKOUQ\Config_DKQBNWAT\ TARGET=StateChartCoderVSM %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building StateChartCoderWx
echo **********************************
make -j 2 -C components_WGNBOFKH\Component_StateChartCoderWx\Config_Windows_Release\ TARGET=StateChartCoderWx %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building Astade
echo **********************************
make -j 2 -C components_WGNBOFKH\component_KSEQOEET\Config_LXNVUSPP\ TARGET=Astade %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building ResourceEdit
echo **********************************
make -j 2 -C components_WGNBOFKH\Component_BZBVDSZR\Windows_Rea\ TARGET=ResourceEdit %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building OMDgenerator
echo **********************************
make -j 2 -C components_WGNBOFKH\Component_OMDgenerator\Windows_Rea\ TARGET=OMDgenerator %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building StateChartDrawer
echo **********************************
make -j 2 -C components_WGNBOFKH\Component_EIFKVZMS\Windows_Rea\ TARGET=StateChartDrawer %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building AstadeDraw
echo **********************************
make -j 2 -C components_WGNBOFKH\Component_GZQBNSVE\Config_CLKAOZUD\ TARGET=AstadeDraw %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building Trace2UML
echo **********************************
make -j 2 -C Components_Trace2UML_components\Component_Trace2UML\Config_Windows_Release\ TARGET=Trace2UML %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building instrument
echo **********************************
make -j 2 -C Components_Trace2UML_components\Component_instrument\Config_Windows\ TARGET=instrument %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo **********************************
echo Building WindowsInstallHelper
echo **********************************
make -j 2 -C Components_ZFTMQEHP\Component_RIXFSVSY\Config_NWJYUSSR\ TARGET=WindowsInstallHelper %1 
@if %errorlevel% NEQ 0 goto ERROR_MAKE

@if "%1" == "clean" goto END
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
@echo MAKE failed
cd ..
@goto END

:ERROR
echo ##################################
@echo Building installer failed
:END
