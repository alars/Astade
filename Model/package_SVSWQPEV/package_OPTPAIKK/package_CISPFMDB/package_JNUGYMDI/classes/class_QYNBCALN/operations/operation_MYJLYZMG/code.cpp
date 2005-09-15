parentFolder.AppendDir(wxString("Package_") + GUID());
parentFolder.SetFullName("ModelNode.ini");

if (!parentFolder.Mkdir( parentFolder.GetPath()))
	return NULL;

wxFileConfig theConfig(wxEmptyString,wxEmptyString,parentFolder.GetFullPath());

theConfig.Write("Astade/Name","Package");
theConfig.Write("Astade/Type",long(ITEM_IS_PACKAGE | ITEM_IS_FOLDER));
theConfig.Write("Astade/ID",IDSTRING);
theConfig.Write("Astade/LastChanged",wxGetUTCTime());

return new AdePackage(parentFolder);



