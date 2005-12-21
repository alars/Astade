wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString isVirtual = theConfig.Read("Astade/Virtual");

return isVirtual == "yes";