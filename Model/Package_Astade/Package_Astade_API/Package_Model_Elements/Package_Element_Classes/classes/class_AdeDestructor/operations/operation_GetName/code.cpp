//~~ wxString GetName() [AdeDestructor] ~~
wxFileName classFileName = myFileName;

int i = classFileName.GetDirCount();
classFileName.RemoveDir(i - 1);
classFileName.RemoveDir(i - 2);
classFileName.SetFullName(wxS("ModelNode.ini"));

wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,classFileName.GetFullPath());

return wxS("~") + theConfig.Read(wxS("Astade/Name"), wxS("<name unknown>"));
