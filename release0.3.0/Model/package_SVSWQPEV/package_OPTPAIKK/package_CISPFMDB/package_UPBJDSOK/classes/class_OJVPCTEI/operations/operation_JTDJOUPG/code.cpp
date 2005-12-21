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

return parentFolder;