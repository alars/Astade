//~~ wxFileName CreateCopy(wxFileName parentPath) [AdePort] ~~
wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

wxString suffix;
if (aFileName.GetPath() == myFileName.GetPath())
	suffix = wxS("_copied");

theConfig.Write(wxS("Astade/Name"), myConfig->Read(wxS("Astade/Name")) + suffix);
theConfig.Write(wxS("Astade/Description"), myConfig->Read(wxS("Astade/Description")));
theConfig.Write(wxS("Astade/delegate"), myConfig->Read(wxS("Astade/delegate")));
theConfig.Write(wxS("Astade/DelegationObject"), myConfig->Read(wxS("Astade/DelegationObject")));
theConfig.Write(wxS("Astade/DelegationPort"), myConfig->Read(wxS("Astade/DelegationPort")));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

return aFileName;
