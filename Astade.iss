[Setup]
AppName=Astade
AppVerName=Astade 0.5.0
AppPublisherURL=http://astade.tigris.org
AppSupportURL=http://astade.tigris.org
AppUpdatesURL=http://astade.tigris.org
DefaultDirName={pf}\Astade
DefaultGroupName=Astade
AllowNoIcons=yes
LicenseFile=F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\License.txt
OutputDir=F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade
OutputBaseFilename=Astade-setup-0.5.0
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
Root: HKCR; Subkey: "UseCaseEditFile\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\UseCaseEdit.exe,1"
Root: HKCR; Subkey: "UseCaseEditFile\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\UseCaseEdit.exe"" ""%1"""

[Files]
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Model\components_WGNBOFKH\component_KSEQOEET\config_DCMYDIYK\Astade.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Model\components_WGNBOFKH\Component_EIFKVZMS\Config_RKODQJIG\StateChartDrawer.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Model\components_WGNBOFKH\Component_RAVGAUPS\Config_TGGOWTNB\StateChartCoder.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Model\components_WGNBOFKH\Component_OMDgenerator\Config_XAWRGEZA\OMDgenerator.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Model\components_WGNBOFKH\Component_CppGenerator\Config_IOLYVMPV\CppGenerator.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Model\components_WGNBOFKH\Component_BZBVDSZR\Config_MZLVJMYC\ResourceEdit.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\www\HTMLHelp\help.zip"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Source\Templates\Makefiles\Windows\Makefile"; DestDir: "{app}\Templates\Makefiles\Windows"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Model\components_WGNBOFKH\Component_IXHOAQJM\Config_QPVYHHCF\UseCaseEdit.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Model\components_WGNBOFKH\Component_RIXFSVSY\Config_ODQRVDCJ\WindowsInstallHelper.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\gpl.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\License.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\LiteEdit.ini"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Programme\Lite Edit\LiteEdit.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Programme\Lite Edit\C++.lang"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Programme\Lite Edit\LiteEditHelp.html"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\trace2uml\Model\Components_LGPLTGDP\Component_TYWOOIDA\Config_GKNDYRWM\Trace2UML.exe"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[INI]
Filename: "{app}\Astade.url"; Section: "InternetShortcut"; Key: "URL"; String: "http://astade.tigris.org"
Filename: "{app}\cppReference.url"; Section: "InternetShortcut"; Key: "URL"; String: "http://cppreference.com/"

[Icons]
Name: "{group}\Astade"; Filename: "{app}\Astade.exe"
Name: "{group}\UseCaseEdit"; Filename: "{app}\UseCaseEdit.exe"
Name: "{group}\Trace2UML"; Filename: "{app}\Trace2UML.exe"
Name: "{group}\cppReference"; Filename: "{app}\cppReference.url"
Name: "{group}\{cm:ProgramOnTheWeb,Astade}"; Filename: "{app}\Astade.url"
Name: "{group}\{cm:UninstallProgram,Astade}"; Filename: "{uninstallexe}"
Name: "{userdesktop}\Astade"; Filename: "{app}\Astade.exe"; Tasks: desktopicon
Name: "{userdesktop}\UseCaseEdit"; Filename: "{app}\UseCaseEdit.exe"; Tasks: desktopicon
Name: "{userdesktop}\Trace2UML"; Filename: "{app}\Trace2UML.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\WindowsInstallHelper.exe";  Flags: runhidden
Filename: "{app}\Astade.exe"; Description: "{cm:LaunchProgram,Astade}"; Flags: nowait postinstall skipifsilent

[UninstallDelete]
Type: files; Name: "{app}\Astade.url"
Type: files; Name: "{app}\cppReference.url"
Type: files; Name: "{app}\omd.bat"
Type: files; Name: "{app}\sc.bat"

