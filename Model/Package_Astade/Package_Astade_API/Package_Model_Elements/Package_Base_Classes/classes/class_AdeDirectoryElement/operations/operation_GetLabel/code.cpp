wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
return theConfig.Read(wxS("Astade/Name"), wxS("<name unknown>"));
