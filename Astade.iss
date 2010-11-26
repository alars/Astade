#include "Model/components_WGNBOFKH/component_KSEQOEET/manual/AstadeVersion.h"
#define AppName "Astade"


; these macros describe where to find the MinGW DLL
; the DLL is needed by Astade....
#define MINGW_PATH "C:/MinGW-i686/bin"
#define MINGW_DLL "mingwm10.dll"

; this path describes where to find LiteEdit
; revisit - no absolute paths !
#define InstallPathLE "C:\Programme\Astade"

[Setup]
AppName={#AppName}
AppVerName={#AppName} {#AstadeVersion}
AppPublisherURL=http://astade.tigris.org
AppSupportURL=mailto:users@astade.tigris.org
AppUpdatesURL=http://astade.tigris.org
DefaultDirName={pf}\{#AppName}
DefaultGroupName={#AppName}
AllowNoIcons=yes
LicenseFile=License.txt
OutputDir=Source\Packages\Windows
OutputBaseFilename={#AppName}-setup-{#AstadeVersion}
Compression=lzma
SolidCompression=yes
ChangesEnvironment=yes
ChangesAssociations=yes

[Languages]
Name: "eng"; MessagesFile: "compiler:Default.isl"

[Dirs]
Name: "{app}\Model"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Registry]
Root: HKCR; Subkey: ".seq"; ValueType: string; ValueName: ""; ValueData: "Trace2UMLFile"; Flags: uninsdeletevalue
Root: HKCR; Subkey: "Trace2UMLFile"; ValueType: string; ValueName: ""; ValueData: "UML sequence Diagram"; Flags: uninsdeletekey
Root: HKCR; Subkey: "Trace2UMLFile\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\Trace2UML.exe,1"
Root: HKCR; Subkey: "Trace2UMLFile\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\Trace2UML.exe"" ""%1"""
Root: HKCR; Subkey: ".ucm"; ValueType: string; ValueName: ""; ValueData: "UseCaseEditFile"; Flags: uninsdeletevalue
Root: HKCR; Subkey: "UseCaseEditFile"; ValueType: string; ValueName: ""; ValueData: "UML use case Diagram"; Flags: uninsdeletekey
Root: HKCR; Subkey: "UseCaseEditFile\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\AstadeDraw.exe,1"
Root: HKCR; Subkey: "UseCaseEditFile\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\AstadeDraw.exe"" ""%1"""

[Files]
Source: "Model\components_WGNBOFKH\component_KSEQOEET\Config_LXNVUSPP\Astade.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#MINGW_PATH}/{#MINGW_DLL}"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\components_WGNBOFKH\Component_EIFKVZMS\Windows_Rea\StateChartDrawer.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\components_WGNBOFKH\Component_RAVGAUPS\Config_PATMRBOG\StateChartCoder.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\components_WGNBOFKH\Component_StateChartCoderWx\Config_Windows_Release\StateChartCoderWx.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\Components_ZLRQZKQB\Component_DJLKKOUQ\Config_DKQBNWAT\StateChartCoderVSM.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\components_WGNBOFKH\Component_CBEUPFRX\Config_KKIPLJZV\StateChartCoderACF.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\components_WGNBOFKH\Component_StateChartCoderACF++\Config_Windows_Release\StateChartCoderACF++.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\components_WGNBOFKH\Component_FOGYFECV\Windows_REA\StateChartCoderC.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\components_WGNBOFKH\Component_OMDgenerator\Windows_Rea\OMDgenerator.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\components_WGNBOFKH\Component_CppGenerator\Config_CPGULUJR\CppGenerator.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\components_WGNBOFKH\Component_CGenerator\Windows_REA\CGenerator.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\components_WGNBOFKH\Component_XZAWFDAN\Config_OPEOVEFK\AstadeGenerate.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\components_WGNBOFKH\Component_BZBVDSZR\Windows_Rea\ResourceEdit.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\Components_Trace2UML_components\Component_Trace2UML\Config_Windows_Release\Trace2UML.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\components_WGNBOFKH\Component_GZQBNSVE\Config_CLKAOZUD\AstadeDraw.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Model\Components_ZFTMQEHP\Component_RIXFSVSY\Config_NWJYUSSR\WindowsInstallHelper.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "www\HTMLHelp\help.zip"; DestDir: "{app}"; Flags: ignoreversion
Source: "Source\Templates\*"; DestDir: "{app}\Templates"; Flags: recursesubdirs
Source: "gpl.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "License.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "LiteEdit.ini"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#InstallPathLE}\LiteEdit.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#InstallPathLE}\C++.lang"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#InstallPathLE}\LiteEditHelp.html"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[INI]
Filename: "{app}\Astade.url"; Section: "InternetShortcut"; Key: "URL"; String: "http://astade.tigris.org"
Filename: "{app}\cppReference.url"; Section: "InternetShortcut"; Key: "URL"; String: "http://cppreference.com/"

[Icons]
Name: "{group}\Astade"; Filename: "{app}\Astade.exe"
Name: "{group}\AstadeDraw"; Filename: "{app}\AstadeDraw.exe"
Name: "{group}\Trace2UML"; Filename: "{app}\Trace2UML.exe"
Name: "{group}\cppReference"; Filename: "{app}\cppReference.url"
Name: "{group}\{cm:ProgramOnTheWeb,Astade}"; Filename: "{app}\Astade.url"
Name: "{userdesktop}\Astade"; Filename: "{app}\Astade.exe"; Tasks: desktopicon
Name: "{userdesktop}\AstadeDraw"; Filename: "{app}\AstadeDraw.exe"; Tasks: desktopicon
Name: "{userdesktop}\Trace2UML"; Filename: "{app}\Trace2UML.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\WindowsInstallHelper.exe";  Flags: runhidden
Filename: "{app}\Astade.exe"; Description: "{cm:LaunchProgram,Astade}"; Flags: nowait postinstall skipifsilent

[UninstallDelete]
Type: files; Name: "{app}\Astade.url"
Type: files; Name: "{app}\cppReference.url"
Type: files; Name: "{app}\omd.bat"
Type: files; Name: "{app}\sc.bat"

