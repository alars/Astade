wxString uniqueID(GUID());

if (useGUID)
	parentFolder.AppendDir(name + "_" + uniqueID);
else
	parentFolder.AppendDir(name);

parentFolder.SetFullName("ModelNode.ini");

if (!parentFolder.Mkdir(parentFolder.GetPath()))
	return parentFolder;

wxFileConfig theConfig(wxEmptyString, wxEmptyString, parentFolder.GetFullPath());

theConfig.Write("Astade/Name", name);
theConfig.Write("Astade/Type", elementType | ITEM_IS_FOLDER);
theConfig.Write("Astade/ID", IDSTRING);
theConfig.Write("Astade/LastChanged", wxGetUTCTime());

AdeGUIDCache::Instance()->AddEntry(parentFolder, uniqueID);
theConfig.Write("Astade/GUID", uniqueID);

theConfig.Flush();

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

if (theRevisionControl->IsAddSupported())
{
	wxFileName dirName(parentFolder);
	dirName.SetFullName(wxEmptyString);
	int ret = theRevisionControl->Add(dirName);
	ret = theRevisionControl->Add(parentFolder);
/*
	wxArrayString output = theRevisionControl->GetOutput();
	wxString message;
	for (size_t i = 0; i < output.GetCount(); i++)
		message += output[i] + "\n";
*/
}

return parentFolder;
