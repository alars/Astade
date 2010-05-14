wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
theConfig.Write(wxS("Astade/Repository"), repositoryName);
