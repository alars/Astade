//~~ wxFileName CreateCopy(wxFileName parentPath) [AdeConnection] ~~
wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

wxString suffix;
if (aFileName.GetPath() == myFileName.GetPath())
	suffix = wxS("_copied");

theConfig.Write(wxS("Astade/Name"), myConfig->Read(wxS("Astade/Name")) + suffix);
theConfig.Write(wxS("Astade/InputObject"), myConfig->Read(wxS("Astade/InputObject")));
theConfig.Write(wxS("Astade/InputPort"), myConfig->Read(wxS("Astade/InputPort")));
theConfig.Write(wxS("Astade/OutputObject"), myConfig->Read(wxS("Astade/OutputObject")));
theConfig.Write(wxS("Astade/OutputPort"), myConfig->Read(wxS("Astade/OutputPort")));
theConfig.Write(wxS("Astade/Description"), myConfig->Read(wxS("Astade/Description")));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

return aFileName;
