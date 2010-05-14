wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
theConfig.Write(wxS("Astade/RepositoryProject"), projectName);
