@echo off
set GEN="%ProgramFiles%\Astade\AstadeGenerate.exe"

@set PWD=%~dp0

@IF NOT EXIST regenerate_all.bat GOTO :ERROR_CALL

echo ***********************************
echo **  generate all Components in   **
echo **  the ASTADE model             **
echo ***********************************
echo .
echo ***********************************
cd Model
set BUILD_TARGET=AstadeAPI
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_AstadeAPI\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=AstadeGraphLib
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_CDFBZLFN\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=Tracelib
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_AstadeFramework\Component_TraceLib\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=AstadeGenerate
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_XZAWFDAN\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=CGenerator
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_CGenerator\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=CppGenerator
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_CppGenerator\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartCoder
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_RAVGAUPS\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartCoderC
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_FOGYFECV\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartCoderVSM
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_ZLRQZKQB\Component_DJLKKOUQ\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartCoderACF
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_CBEUPFRX\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartCoderACF++
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_StateChartCoderACF++\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartCoderWx
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_StateChartCoderWx\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=Astade
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\component_KSEQOEET\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=ResourceEdit
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_BZBVDSZR\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=CSDgenerator
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_CSDgenerator\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=OMDgenerator
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_OMDgenerator\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartDrawer 
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_EIFKVZMS\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=AstadeDraw
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\components_WGNBOFKH\Component_GZQBNSVE\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=Trace2UML
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Trace2UML_components\Component_Trace2UML\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=WindowsInstallHelper
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_ZFTMQEHP\Component_RIXFSVSY\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
cd ..
goto EXIT_BUILD

:ERROR_CALL
@echo *********************************************************
@echo * Error on calling this batch!                          *
@echo * You -must- call this batch from within its directory! *
@echo * Change your working directory to the location where   *
@echo * this batch file lives and try again.                  *
@echo *********************************************************
GOTO EXIT_BUILD

:ERROR_MAKE
@echo ******************************
@echo ** Error making %BUILD_TARGET%
@echo ******************************
cd ..

:EXIT_BUILD
pause
