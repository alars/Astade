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
{
	int ret = theRevisionControl->Add(parentFolder);
	wxArrayString output = theRevisionControl->GetOutput();
	wxString message;

	for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";

	if (ret!=0)
		wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);
}

return parentFolder;