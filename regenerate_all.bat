@echo off
set GEN=%ProgramFiles%\Astade\AstadeGenerate.exe
echo ***********************************
echo ** generating all Components in  **
echo ** the ASTADE model              **
echo ***********************************
echo .
echo ***********************************
echo AstadeAPI
%GEN% /c .\Model\components_WGNBOFKH\Component_AstadeAPI\ModelNode.ini
echo ***********************************
echo ActivityChartDrawer
%GEN% /c .\Model\components_WGNBOFKH\Component_YIIYAPSY\ModelNode.ini
echo ***********************************
echo Astade
%GEN% /c .\Model\components_WGNBOFKH\component_KSEQOEET\ModelNode.ini
echo ***********************************
echo AstadeGenerate
%GEN% /c .\Model\components_WGNBOFKH\Component_XZAWFDAN\ModelNode.ini
echo ***********************************
echo CppGenerator
%GEN% /c .\Model\components_WGNBOFKH\Component_CppGenerator\ModelNode.ini
echo ***********************************
echo OMDgenerator
%GEN% /c .\Model\components_WGNBOFKH\Component_OMDgenerator\ModelNode.ini
echo ***********************************
echo ResourceEdit
%GEN% /c .\Model\components_WGNBOFKH\Component_BZBVDSZR\ModelNode.ini
echo ***********************************
echo StateChart Coder (AST)
%GEN% /c .\Model\components_WGNBOFKH\Component_RAVGAUPS\ModelNode.ini
echo ***********************************
echo StateChartDrawer 
%GEN% /c .\Model\components_WGNBOFKH\Component_EIFKVZMS\ModelNode.ini
echo ***********************************
echo UseCaseEdit
%GEN% /c .\Model\components_WGNBOFKH\Component_IXHOAQJM\ModelNode.ini
rem  not usefull to build...
rem Test Tracelib
rem  %GEN% /c .\Model\Components_AstadeFramework\Component_TraceLib\ModelNode.ini
rem Test Revision Control
rem %GEN% /c .\Model\Components_UnitTests\Component_RevisionControl\ModelNode.ini
rem Test Stair Case
rem %GEN% /c .\Model\Components_UnitTests\Component_XHXNZZTZ\ModelNode.ini
echo ***********************************
echo WindowsInstallHelper
%GEN% /c .\Model\Components_ZFTMQEHP\Component_RIXFSVSY\ModelNode.ini
echo ***********************************
echo StateChartCoderCdSys
%GEN% /c .\Model\Components_ZLRQZKQB\Component_StateChartCoderCdSys\ModelNode.ini
echo ***********************************
echo StateChartCoderVSM
%GEN% /c .\Model\Components_ZLRQZKQB\Component_DJLKKOUQ\ModelNode.ini
echo ***********************************
echo StateChartCoderWx
%GEN% /c .\Model\Components_ZLRQZKQB\Component_LUAJBDMB\ModelNode.ini

pause
