wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
return theConfig.Read(wxS("Astade/Explicit")) == wxS("yes");
