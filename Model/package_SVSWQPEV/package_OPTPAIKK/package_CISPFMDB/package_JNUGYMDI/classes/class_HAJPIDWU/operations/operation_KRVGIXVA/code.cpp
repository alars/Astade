wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());

wxString theName = theConfig.Read("Astade/Name");
wxString theCodingType = theConfig.Read("Astade/CodingType");
wxString theDefault = theConfig.Read("Astade/Default");

if (!theCodingType.empty())
	theName = theCodingType + " " + theName;

if (!theDefault.empty())
	theName = theName + " = " + theDefault;

return theName;
