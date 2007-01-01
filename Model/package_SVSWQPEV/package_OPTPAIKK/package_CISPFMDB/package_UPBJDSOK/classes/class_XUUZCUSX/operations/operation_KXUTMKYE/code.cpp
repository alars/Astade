wxString uniqueID;

if (useGUID)
{
	uniqueID = GUID();
	parentFolder.AppendDir(name + wxString("_") + uniqueID);
}
else
	parentFolder.AppendDir(name);

parentFolder.SetFullName("ModelNode.ini");

if (!parentFolder.Mkdir( parentFolder.GetPath()))
	return parentFolder;

wxFileConfig theConfig(wxEmptyString,wxEmptyString,parentFolder.GetFullPath());

theConfig.Write("Astade/Name",name);
theConfig.Write("Astade/Type",long(elementType | ITEM_IS_FOLDER));
theConfig.Write("Astade/ID",IDSTRING);
theConfig.Write("Astade/LastChanged",wxGetUTCTime());

if (!uniqueID.empty())
	theConfig.Write("Astade/uniqueID",uniqueID);

theConfig.Flush();

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

if (theRevisionControl->IsAddSupported())
{
	wxFileName dirName(parentFolder);
	dirName.SetFullName(wxEmptyString);
	int ret = theRevisionControl->Add(dirName);
	ret = theRevisionControl->Add(parentFolder);
	wxArrayString output = theRevisionControl->GetOutput();
	wxString message;

	for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";

	if (ret!=0)
		wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);
}

return parentFolder;