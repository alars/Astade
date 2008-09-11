@echo off
set GEN=%ProgramFiles%\Astade\AstadeGenerate.exe
echo ***********************************
echo **  generate all Components in   **
echo **  the ASTADE model             **
echo ***********************************
echo .
echo ***********************************
cd Model
echo AstadeAPI
%GEN% /c .\components_WGNBOFKH\Component_AstadeAPI\
echo ***********************************
echo Tracelib
%GEN% /c .\Components_AstadeFramework\Component_TraceLib\
echo ***********************************
echo AstadeGenerate
%GEN% /c .\components_WGNBOFKH\Component_XZAWFDAN\
echo ***********************************
echo CGenerator
%GEN% /c .\components_WGNBOFKH\Component_CGenerator\
echo ***********************************
echo CppGenerator
%GEN% /c .\components_WGNBOFKH\Component_CppGenerator\
echo ***********************************
echo StateChartCoder
%GEN% /c .\components_WGNBOFKH\Component_RAVGAUPS\
echo ***********************************
echo StateChartCoderC
%GEN% /c .\Components_ZLRQZKQB\Component_FOGYFECV\
echo ***********************************
echo StateChartCoderVSM
%GEN% /c .\Components_ZLRQZKQB\Component_DJLKKOUQ\
echo ***********************************
echo StateChartCoderWx
%GEN% /c .\Components_ZLRQZKQB\Component_LUAJBDMB\
echo ***********************************
echo Astade
%GEN% /c .\components_WGNBOFKH\component_KSEQOEET\
echo ***********************************
echo ResourceEdit
%GEN% /c .\components_WGNBOFKH\Component_BZBVDSZR\
echo ***********************************
echo ActivityChartDrawer
%GEN% /c .\components_WGNBOFKH\Component_YIIYAPSY\
echo ***********************************
echo OMDgenerator
%GEN% /c .\components_WGNBOFKH\Component_OMDgenerator\
echo ***********************************
echo StateChartDrawer 
%GEN% /c .\components_WGNBOFKH\Component_EIFKVZMS\
echo ***********************************
echo UseCaseEdit
%GEN% /c .\components_WGNBOFKH\Component_IXHOAQJM\
echo ***********************************
echo Trace2UML
%GEN% /c .\Components_LGPLTGDP\Component_TYWOOIDA\
echo ***********************************
echo WindowsInstallHelper
%GEN% /c .\Components_ZFTMQEHP\Component_RIXFSVSY\

rem  not useful to build...
rem Test Revision Control
rem %GEN% /c .\Components_UnitTests\Component_RevisionControl\
rem Test Stair Case
rem %GEN% /c .\Components_UnitTests\Component_XHXNZZTZ\

pause
