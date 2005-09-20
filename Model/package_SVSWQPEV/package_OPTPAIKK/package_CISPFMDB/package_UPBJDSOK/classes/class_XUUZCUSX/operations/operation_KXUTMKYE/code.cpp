if (useGUID)
	parentFolder.AppendDir(name + wxString("_") + GUID());
else
	parentFolder.AppendDir(name);

parentFolder.SetFullName("ModelNode.ini");

if (!parentFolder.Mkdir( parentFolder.GetPath()))
	return;

wxFileConfig theConfig(wxEmptyString,wxEmptyString,parentFolder.GetFullPath());

theConfig.Write("Astade/Name",name);
theConfig.Write("Astade/Type",long(elementType | ITEM_IS_FOLDER));
theConfig.Write("Astade/ID",IDSTRING);
theConfig.Write("Astade/LastChanged",wxGetUTCTime());

