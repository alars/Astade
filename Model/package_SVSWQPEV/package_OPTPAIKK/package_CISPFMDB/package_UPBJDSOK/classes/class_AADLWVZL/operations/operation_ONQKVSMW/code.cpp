wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString isStatic = theConfig.Read("Astade/Static");

return isStatic == "yes";