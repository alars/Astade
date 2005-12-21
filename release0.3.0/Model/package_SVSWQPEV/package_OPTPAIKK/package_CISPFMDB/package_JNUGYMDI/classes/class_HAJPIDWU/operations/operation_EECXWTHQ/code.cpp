wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString isBold = theConfig.Read("Astade/Const");

return isBold == "yes";