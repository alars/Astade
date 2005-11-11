[Setup]
AppName=Astade
AppVerName=Astade 0.1.1
AppPublisherURL=http://astade.tigris.org
AppSupportURL=http://astade.tigris.org
AppUpdatesURL=http://astade.tigris.org
DefaultDirName={pf}\Astade
DefaultGroupName=Astade
AllowNoIcons=yes
LicenseFile=F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\License.txt
OutputDir=F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade
OutputBaseFilename=Astade-setup-0.1.1
Compression=lzma
SolidCompression=yes
ChangesEnvironment=yes

[Languages]
Name: "eng"; MessagesFile: "compiler:Default.isl"

[Dirs]
Name: "{app}\Model"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Model\components_WGNBOFKH\component_KSEQOEET\config_DCMYDIYK\Astade.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Source\omd\omd.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Source\qdc\QDC.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Model\components_WGNBOFKH\Component_BZBVDSZR\Config_MZLVJMYC\ResourceEdit.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\www\HTMLHelp\help.zip"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Source\Templates\Makefiles\Windows\Makefile"; DestDir: "{app}\Templates\Makefiles\Windows"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Model\components_WGNBOFKH\Component_RIXFSVSY\Config_ODQRVDCJ\WindowsInstallHelper.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\gpl.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\License.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\Source\Templates\Scripts\Windows\omd.bat"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Dokumente und Einstellungen\Thomas\Eigene Dateien\Astade\LiteEdit.ini"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Programme\Lite Edit\LiteEdit.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Programme\Lite Edit\C++.lang"; DestDir: "{app}"; Flags: ignoreversion
Source: "F:\Programme\Lite Edit\LiteEditHelp.html"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[INI]
Filename: "{app}\Astade.url"; Section: "InternetShortcut"; Key: "URL"; String: "http://astade.tigris.org"

[Icons]
Name: "{group}\Astade"; Filename: "{app}\Astade.exe"
Name: "{group}\{cm:ProgramOnTheWeb,Astade}"; Filename: "{app}\Astade.url"
Name: "{group}\{cm:UninstallProgram,Astade}"; Filename: "{uninstallexe}"
Name: "{userdesktop}\Astade"; Filename: "{app}\Astade.exe"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\Astade"; Filename: "{app}\Astade.exe"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\WindowsInstallHelper.exe";  Flags: runhidden
Filename: "{app}\Astade.exe"; Description: "{cm:LaunchProgram,Astade}"; Flags: nowait postinstall skipifsilent

[UninstallDelete]
Type: files; Name: "{app}\Astade.url"

