wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
theConfig.Write(wxS("Astade/SaveVersion"), aVersion);
