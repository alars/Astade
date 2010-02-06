wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
wxString aGUID;

aGUID = GUID();
theConfig.Write("Astade/GUID",aGUID);

return aGUID;