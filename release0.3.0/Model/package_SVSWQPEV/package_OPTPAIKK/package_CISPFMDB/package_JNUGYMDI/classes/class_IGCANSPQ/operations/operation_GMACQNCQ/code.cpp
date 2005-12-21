wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());

return theConfig.Read("Astade/CodingType",wxString("void"));
