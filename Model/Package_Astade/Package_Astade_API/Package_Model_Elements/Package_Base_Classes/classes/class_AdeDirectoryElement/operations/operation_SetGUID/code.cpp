wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
wxString aGUID(GUID());
theConfig.Write(wxS("Astade/GUID"), aGUID);

return aGUID;
