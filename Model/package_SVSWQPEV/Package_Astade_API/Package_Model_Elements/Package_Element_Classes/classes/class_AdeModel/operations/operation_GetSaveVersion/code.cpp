wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
return theConfig.Read("Astade/SaveVersion",static_cast<long>(0));