wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString theName = theConfig.Read("Astade/Name");
wxString theCodingType = theConfig.Read("Astade/CodingType");

if (theCodingType.size()>0)
	theName = theCodingType + " " + theName;

return theName;