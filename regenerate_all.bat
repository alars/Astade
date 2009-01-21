@echo off
set GEN="%ProgramFiles%\Astade\AstadeGenerate.exe"
echo ***********************************
echo **  generate all Components in   **
echo **  the ASTADE model             **
echo ***********************************
echo .
echo ***********************************
cd Model
echo AstadeAPI
%GEN% /X /c .\components_WGNBOFKH\Component_AstadeAPI\
echo ***********************************
echo Tracelib
%GEN% /X /c .\Components_AstadeFramework\Component_TraceLib\
echo ***********************************
echo AstadeGenerate
%GEN% /X /c .\components_WGNBOFKH\Component_XZAWFDAN\
echo ***********************************
echo CGenerator
%GEN% /X /c .\components_WGNBOFKH\Component_CGenerator\
echo ***********************************
echo CppGenerator
%GEN% /X /c .\components_WGNBOFKH\Component_CppGenerator\
echo ***********************************
echo StateChartCoder
%GEN% /X /c .\components_WGNBOFKH\Component_RAVGAUPS\
echo ***********************************
echo StateChartCoderC
%GEN% /X /c .\components_WGNBOFKH\Component_FOGYFECV\
echo ***********************************
echo StateChartCoderVSM
%GEN% /X /c .\Components_ZLRQZKQB\Component_DJLKKOUQ\
echo ***********************************
echo StateChartCoderCdSys
%GEN% /X /c .\Components_ZLRQZKQB\Component_StateChartCoderCdSys\
echo ***********************************
echo StateChartCoderWx
%GEN% /X /c .\Components_ZLRQZKQB\Component_LUAJBDMB\
echo ***********************************
echo Astade
%GEN% /X /c .\components_WGNBOFKH\component_KSEQOEET\
echo ***********************************
echo ResourceEdit
%GEN% /X /c .\components_WGNBOFKH\Component_BZBVDSZR\
echo ***********************************
echo OMDgenerator
%GEN% /X /c .\components_WGNBOFKH\Component_OMDgenerator\
echo ***********************************
echo StateChartDrawer 
%GEN% /X /c .\components_WGNBOFKH\Component_EIFKVZMS\
echo ***********************************
echo UseCaseEdit
%GEN% /X /c .\components_WGNBOFKH\Component_IXHOAQJM\
echo ***********************************
echo Trace2UML
%GEN% /X /c .\Components_LGPLTGDP\Component_TYWOOIDA\
echo ***********************************
echo WindowsInstallHelper
%GEN% /X /c .\Components_ZFTMQEHP\Component_RIXFSVSY\

rem  not useful to build...
rem Test Revision Control
rem %GEN% /X /c .\Components_UnitTests\Component_RevisionControl\
rem Test Stair Case
rem %GEN% /X /c .\Components_UnitTests\Component_XHXNZZTZ\

pause
