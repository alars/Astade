wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

wxString suffix;
if (aFileName.GetPath() == myFileName.GetPath())
	suffix = "_copied";

theConfig.Write("Astade/Name", myConfig->Read("Astade/Name") + suffix);
theConfig.Write("Astade/Type", myConfig->Read("Astade/Type"));
theConfig.Write("Astade/CodingType", myConfig->Read("Astade/CodingType"));
theConfig.Write("Astade/Description", myConfig->Read("Astade/Description"));
theConfig.Write("Astade/Static",  myConfig->Read("Astade/Static"));
theConfig.Write("Astade/Const",  myConfig->Read("Astade/Const"));
theConfig.Write("Astade/Default",  myConfig->Read("Astade/Default"));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

return aFileName;
