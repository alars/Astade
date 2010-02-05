parentPath.RemoveDir(parentPath.GetDirCount()-1);
wxFileName partnerPath = GetPartnerFile();

partnerPath.RemoveDir(partnerPath.GetDirCount()-1);

wxFileName aFileName = CreateNewElement(parentPath,partnerPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

theConfig.Write("Astade/Name",myConfig->Read("Astade/Name"));
theConfig.Write("Astade/Type", myConfig->Read("Astade/Type"));
theConfig.Write("Astade/Description", myConfig->Read("Astade/Description"));
theConfig.Write("Astade/Default", myConfig->Read("Astade/Default"));
theConfig.Write("Astade/RelationType",  myConfig->Read("Astade/RelationType"));
theConfig.Write("Astade/Implementation",  myConfig->Read("Astade/Implementation"));
theConfig.Write("Astade/Multiplicity",  myConfig->Read("Astade/Multiplicity"));
theConfig.Write("Astade/Static",  myConfig->Read("Astade/Static"));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

return aFileName;
