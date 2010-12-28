//~~ wxFileName CreateCopy(wxFileName parentPath) [AdeConnection] ~~
wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

wxString suffix;
if (aFileName.GetPath() == myFileName.GetPath())
	suffix = wxS("_copied");

theConfig.Write(wxS("Astade/Name"), myConfig->Read(wxS("Astade/Name")) + suffix);
theConfig.Write(wxS("Astade/Description"), myConfig->Read(wxS("Astade/Description")));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

return aFileName;
