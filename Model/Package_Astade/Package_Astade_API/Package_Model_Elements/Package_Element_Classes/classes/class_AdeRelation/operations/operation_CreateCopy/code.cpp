//~~ wxFileName CreateCopy(wxFileName parentPath) [AdeRelation] ~~
parentPath.RemoveDir(parentPath.GetDirCount()-1);
wxFileName partnerPath = GetPartnerFile();

partnerPath.RemoveDir(partnerPath.GetDirCount()-1);

wxFileName aFileName = CreateNewElement(parentPath,partnerPath);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());

theConfig.Write(wxS("Astade/Name"), myConfig->Read(wxS("Astade/Name")));
theConfig.Write(wxS("Astade/Type"), myConfig->Read(wxS("Astade/Type")));
theConfig.Write(wxS("Astade/Description"), myConfig->Read(wxS("Astade/Description")));
theConfig.Write(wxS("Astade/Default"), myConfig->Read(wxS("Astade/Default")));
theConfig.Write(wxS("Astade/RelationType"), myConfig->Read(wxS("Astade/RelationType")));
theConfig.Write(wxS("Astade/Implementation"), myConfig->Read(wxS("Astade/Implementation")));
theConfig.Write(wxS("Astade/Multiplicity"), myConfig->Read(wxS("Astade/Multiplicity")));
theConfig.Write(wxS("Astade/Static"), myConfig->Read(wxS("Astade/Static")));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

return aFileName;
