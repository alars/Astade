wxFileName PartnerFile = GetPartnerFile();
int i = PartnerFile.GetDirCount();
PartnerFile.RemoveDir(i);
PartnerFile.RemoveDir(i-1);
PartnerFile.SetFullName("ModelNode.ini");

wxFileConfig thePartnerConfig(wxEmptyString,wxEmptyString,PartnerFile.GetFullPath());

wxString PatrnerName = thePartnerConfig.Read("Astade/Name");

return "from: " + PatrnerName;
