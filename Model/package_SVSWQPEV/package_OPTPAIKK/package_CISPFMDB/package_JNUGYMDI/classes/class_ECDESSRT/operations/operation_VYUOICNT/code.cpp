parentFolder.AppendDir(wxString("Components_") + GUID());
parentFolder.SetFullName("ModelNode.ini");

if (!parentFolder.Mkdir( parentFolder.GetPath()))
	return NULL;

wxFileConfig theConfig(wxEmptyString,wxEmptyString,parentFolder.GetFullPath());

theConfig.Write("Astade/Name","Components");
theConfig.Write("Astade/Type",long(ITEM_IS_COMPONENTS | ITEM_IS_FOLDER));
theConfig.Write("Astade/ID","$Id$");
theConfig.Write("Astade/LastChanged",wxGetUTCTime());

return new AdeComponents(parentFolder);



