//~~ wxFileName CreateNewElement(wxFileName parentFolder, const wxString& name, int elementType, bool useGUID) [AdeFileElement] ~~
if (useGUID)
	parentFolder.SetName(name + wxS("_") + GUID());
else
	parentFolder.SetName(name);

parentFolder.SetExt(wxS("ini"));

wxFileConfig theConfig(wxEmptyString, wxEmptyString, parentFolder.GetFullPath());

theConfig.Write(wxS("Astade/Name"), name);
theConfig.Write(wxS("Astade/Type"), long(elementType));

theConfig.Flush();

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(parentFolder);

return parentFolder;
