wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
return theConfig.Read("Astade/Name","<name unknown>");