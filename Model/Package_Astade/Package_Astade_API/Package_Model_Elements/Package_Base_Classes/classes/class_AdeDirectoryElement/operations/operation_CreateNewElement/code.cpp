//~~ wxFileName CreateNewElement(wxFileName parentFolder, const wxString& name, int elementType, bool useGUID) [AdeDirectoryElement] ~~

wxString uniqueID(GUID());

if (useGUID)
	parentFolder.AppendDir(name + wxS("_") + uniqueID);
else
	parentFolder.AppendDir(name);

parentFolder.SetFullName(wxS("ModelNode.ini"));

if (!parentFolder.Mkdir(parentFolder.GetPath()))
	return parentFolder;

wxFileConfig theConfig(wxEmptyString, wxEmptyString, parentFolder.GetFullPath());

theConfig.Write(wxS("Astade/Name"), name);
theConfig.Write(wxS("Astade/Type"), elementType | ITEM_IS_FOLDER);

AdeGUIDCache::Instance()->AddEntry(parentFolder, uniqueID);
theConfig.Write(wxS("Astade/GUID"), uniqueID);

theConfig.Flush();

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
if (theRevisionControl->IsAddSupported())
{
	wxFileName dirName(parentFolder);
	dirName.SetFullName(wxEmptyString);
	theRevisionControl->Add(dirName);
	theRevisionControl->Add(parentFolder);
}

return parentFolder;
