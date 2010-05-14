wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
return theConfig.Read(wxS("Astade/RepositoryProject"), wxEmptyString);
