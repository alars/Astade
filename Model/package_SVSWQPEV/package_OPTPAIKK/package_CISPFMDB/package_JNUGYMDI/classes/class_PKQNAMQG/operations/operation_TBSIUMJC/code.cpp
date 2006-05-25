parentPath.RemoveDir(parentPath.GetDirCount()-1);
wxFileName partnerPath = GetPartnerFile();

partnerPath.RemoveDir(partnerPath.GetDirCount()-1);

wxFileName aFileName = CreateNewElement(parentPath,partnerPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());
wxFileConfig copyConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

theConfig.Write("Astade/Name",copyConfig.Read("Astade/Name"));
theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));
theConfig.Write("Astade/Description", copyConfig.Read("Astade/Description"));
theConfig.Write("Astade/Default", copyConfig.Read("Astade/Default"));
theConfig.Write("Astade/RelationType",  copyConfig.Read("Astade/RelationType"));
theConfig.Write("Astade/Implementation",  copyConfig.Read("Astade/Implementation"));
theConfig.Write("Astade/Multiplicity",  copyConfig.Read("Astade/Multiplicity"));

return aFileName;