wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
theConfig.Write("Astade/SaveVersion",aVersion);