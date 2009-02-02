@echo off
set GEN="%ProgramFiles%\Astade\AstadeGenerate.exe"

@set PWD=%~dp0
@set MODLEPATH=%PWD%\Model

@IF NOT EXIST regenerate_all.bat GOTO :ERROR_CALL

echo ***********************************
echo **  generate all Components in   **
echo **  the ASTADE model             **
echo ***********************************
echo .
echo ***********************************
cd Model
echo AstadeAPI
set BUILD_TARGET=AstadeAPI
%GEN% /X /c .\components_WGNBOFKH\Component_AstadeAPI\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo Tracelib
set BUILD_TARGET=Tracelib
%GEN% /X /c .\Components_AstadeFramework\Component_TraceLib\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo AstadeGraphLib
set BUILD_TARGET=AstadeGraphLib
%GEN% /X /c .\components_WGNBOFKH\Component_CDFBZLFN\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo AstadeGenerate
set BUILD_TARGET=AstadeGenerate
%GEN% /X /c .\components_WGNBOFKH\Component_XZAWFDAN\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo CGenerator
set BUILD_TARGET=CGenerator
%GEN% /X /c .\components_WGNBOFKH\Component_CGenerator\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo CppGenerator
set BUILD_TARGET=CppGenerator
%GEN% /X /c .\components_WGNBOFKH\Component_CppGenerator\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo StateChartCoder
set BUILD_TARGET=StateChartCoder
%GEN% /X /c .\components_WGNBOFKH\Component_RAVGAUPS\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo StateChartCoderC
set BUILD_TARGET=StateChartCoderC
%GEN% /X /c .\components_WGNBOFKH\Component_FOGYFECV\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo StateChartCoderVSM
set BUILD_TARGET=StateChartCoderVSM
%GEN% /X /c .\Components_ZLRQZKQB\Component_DJLKKOUQ\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo StateChartCoderWx
set BUILD_TARGET=StateChartCoderWx
%GEN% /X /c .\Components_ZLRQZKQB\Component_LUAJBDMB\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo Astade
set BUILD_TARGET=Astade
%GEN% /X /c .\components_WGNBOFKH\component_KSEQOEET\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo ResourceEdit
set BUILD_TARGET=ResourceEdit
%GEN% /X /c .\components_WGNBOFKH\Component_BZBVDSZR\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo OMDgenerator
set BUILD_TARGET=OMDgenerator
%GEN% /X /c .\components_WGNBOFKH\Component_OMDgenerator\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo StateChartDrawer 
set BUILD_TARGET=StateChartDrawer 
%GEN% /X /c .\components_WGNBOFKH\Component_EIFKVZMS\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo UseCaseEdit
set BUILD_TARGET=UseCaseEdit
%GEN% /X /c .\components_WGNBOFKH\Component_IXHOAQJM\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo Trace2UML
set BUILD_TARGET=Trace2UML
%GEN% /X /c .\Components_LGPLTGDP\Component_TYWOOIDA\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
echo WindowsInstallHelper
set BUILD_TARGET=WindowsInstallHelper
%GEN% /X /c .\Components_ZFTMQEHP\Component_RIXFSVSY\
@if %errorlevel% NEQ 0 goto ERROR_MAKE

goto EXIT_BUILD

:ERROR_CALL
@echo *********************************************************
@echo * Error on call this batch!                             *
@echo * You -must- call this batch from within its directory! *
@echo * Change your working directory to the location this    *
@echo * batch file lives and run again.                       *
@echo *********************************************************
GOTO EXIT_BUILD

:ERROR_MAKE
@echo *********************
@echo ** ERROR bei MAKE ***
@echo ** von %BUILD_TARGET%
@echo *********************
:EXIT_BUILD

pause
