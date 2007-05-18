if (useGUID)
	parentFolder.SetName(name + wxString("_") + GUID());
else
	parentFolder.SetName(name);

parentFolder.SetExt("ini");

wxFileConfig theConfig(wxEmptyString,wxEmptyString,parentFolder.GetFullPath());

theConfig.Write("Astade/Name",name);
theConfig.Write("Astade/Type",long(elementType));
theConfig.Write("Astade/ID",IDSTRING);
theConfig.Write("Astade/LastChanged",wxGetUTCTime());

theConfig.Flush();

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(parentFolder);

return parentFolder;