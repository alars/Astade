#include "Model/Components_Trace2UML_components/Component_Trace2UML/manual/Trace2UMLVersion.h"
#define AppName "Trace2UML"


; these macros describe where to find the MinGW DLL
; the DLL is needed by Astade....
#define MINGW_PATH "Source"
#define MINGW_DLL "mingwm10.dll"


[Setup]
AppName={#AppName}
AppVerName={#AppName} {#Trace2UMLVersion}
AppPublisherURL=http://trace2uml.tigris.org
AppSupportURL=mailto:users@astade.tigris.org
AppUpdatesURL=http://trace2uml.tigris.org
DefaultDirName={pf}\Astade
DefaultGroupName=Astade
AllowNoIcons=yes
LicenseFile=License.txt
OutputDir=Source\Packages\Windows
OutputBaseFilename={#AppName}-setup-{#Trace2UMLVersion}
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

[Files]
Source: "Model/Components_Trace2UML_components/Component_Trace2UML/Config_MingwCross/Trace2UML.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#MINGW_PATH}/*.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "gpl.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "License.txt"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[INI]
Filename: "{app}\Astade.url"; Section: "InternetShortcut"; Key: "URL"; String: "http://astade.tigris.org"

[Icons]
Name: "{group}\Trace2UML"; Filename: "{app}\Trace2UML.exe"
Name: "{group}\{cm:ProgramOnTheWeb,Astade}"; Filename: "{app}\Astade.url"
Name: "{userdesktop}\Trace2UML"; Filename: "{app}\Trace2UML.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\Trace2UML.exe"; Description: "{cm:LaunchProgram,Trace2UML}"; Flags: nowait postinstall skipifsilent

