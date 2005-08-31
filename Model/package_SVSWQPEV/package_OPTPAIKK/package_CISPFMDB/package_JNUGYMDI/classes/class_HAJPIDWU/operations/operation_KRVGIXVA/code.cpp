wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString theName = theConfig.Read("Astade/Name");
wxString theCodingType = theConfig.Read("Astade/CodingType");
wxString theDefault = theConfig.Read("Astade/Default");

if (theCodingType.size()>0)
	theName = theCodingType + " " + theName;

if (theDefault.size()>0)
	theName = theName + " = " + theDefault;

return theName;