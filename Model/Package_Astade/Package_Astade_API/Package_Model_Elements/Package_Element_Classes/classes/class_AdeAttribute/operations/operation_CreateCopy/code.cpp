//~~ wxFileName CreateCopy(wxFileName parentPath) [AdeAttribute] ~~
wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

wxString suffix;
if (aFileName.GetPath() == myFileName.GetPath())
	suffix = wxS("_copied");

theConfig.Write(wxS("Astade/Name"), myConfig->Read(wxS("Astade/Name")) + suffix);
theConfig.Write(wxS("Astade/Type"), myConfig->Read(wxS("Astade/Type")));
theConfig.Write(wxS("Astade/CodingType"), myConfig->Read(wxS("Astade/CodingType")));
theConfig.Write(wxS("Astade/Description"), myConfig->Read(wxS("Astade/Description")));
theConfig.Write(wxS("Astade/Static"),  myConfig->Read(wxS("Astade/Static")));
theConfig.Write(wxS("Astade/Const"),  myConfig->Read(wxS("Astade/Const")));
theConfig.Write(wxS("Astade/Default"),  myConfig->Read(wxS("Astade/Default")));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

return aFileName;
