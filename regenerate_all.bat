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
%GEN% /X /c .\Components_Astade_components\Component_AstadeAPI\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=AstadeGraphLib
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_AstadeGraphLib\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=Tracelib
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_AstadeFramework\Component_TraceLib\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=AstadeGenerate
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_AstadeGenerate\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=CGenerator
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_CGenerator\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=CppGenerator
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_CppGenerator\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartCoder
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_StateChartCoder\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartCoderC
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_StateChartCoderC\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartCoderVSM
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Specials\Component_StateChartCoderVSM\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartCoderACF
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_StateChartCoderACF\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartCoderACF++
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_StateChartCoderACF++\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartCoderQt
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_StateChartCoderQt\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartCoderWx
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_StateChartCoderWx\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=Astade
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_Astade\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=ResourceEdit
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_ResourceEdit\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=CSDgenerator
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_CSDgenerator\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=OMDgenerator
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_OMDgenerator\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=StateChartDrawer 
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_StateChartDrawer\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=AstadeDraw
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Astade_components\Component_AstadeDraw\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=Trace2UML
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Trace2UML_components\Component_Trace2UML\
@if %errorlevel% NEQ 0 goto ERROR_MAKE
echo ***********************************
set BUILD_TARGET=WindowsInstallHelper
echo *** %BUILD_TARGET% ***
%GEN% /X /c .\Components_Helper_components\Component_WindowsInstallHelper\
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
