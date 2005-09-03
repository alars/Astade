wxFileName PartnerFile = GetPartnerFile();
int i = PartnerFile.GetDirCount();
PartnerFile.RemoveDir(i);
PartnerFile.RemoveDir(i-1);
PartnerFile.SetFullName("Desktop.ini");

wxFileConfig thePartnerConfig(wxEmptyString,wxEmptyString,wxEmptyString,PartnerFile.GetFullPath());

wxString PatrnerName = thePartnerConfig.Read("Astade/Name");

return "from: " + PatrnerName;