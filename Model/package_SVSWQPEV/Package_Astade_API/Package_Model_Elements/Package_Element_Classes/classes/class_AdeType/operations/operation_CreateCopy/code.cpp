wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

wxString suffix;
if (aFileName.GetPath() == myFileName.GetPath())
	suffix = "_copied";

theConfig.Write("Astade/Name",myConfig->Read("Astade/Name") + suffix);
theConfig.Write("Astade/Type", myConfig->Read("Astade/Type"));
theConfig.Write("Astade/Declaration", myConfig->Read("Astade/Declaration"));
theConfig.Write("Astade/Description", myConfig->Read("Astade/Description"));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

return aFileName;
