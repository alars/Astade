wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
return theConfig.Read(wxS("Astade/SaveVersion"), 0L);
