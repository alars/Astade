//~~ wxDateTime GetModificationTime() [AdePorts] ~~
// it's enough to check the folder date, because it has no subfolder
wxFileName aFileName = myFileName;
aFileName.SetFullName(wxEmptyString);
return aFileName.GetModificationTime();