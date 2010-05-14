wxFileName PartnerFile = GetPartnerFile();
int i = PartnerFile.GetDirCount();
PartnerFile.RemoveDir(i - 1);
PartnerFile.SetFullName(wxS("ModelNode.ini"));

wxFileConfig thePartnerConfig(wxEmptyString, wxEmptyString, PartnerFile.GetFullPath());

return thePartnerConfig.Read(wxS("Astade/Name"));
