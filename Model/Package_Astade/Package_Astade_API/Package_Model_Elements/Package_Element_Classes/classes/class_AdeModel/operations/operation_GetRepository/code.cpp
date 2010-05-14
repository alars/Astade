wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
return theConfig.Read(wxS("Astade/Repository"), wxS("<name unknown>"));
