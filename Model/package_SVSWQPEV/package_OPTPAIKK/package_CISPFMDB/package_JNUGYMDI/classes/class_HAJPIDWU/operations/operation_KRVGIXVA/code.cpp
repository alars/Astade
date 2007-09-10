wxString theName = myConfig->Read("Astade/Name");
wxString theCodingType = myConfig->Read("Astade/CodingType");
wxString theDefault = myConfig->Read("Astade/Default");

if (!theCodingType.empty())
	theName = theCodingType + " " + theName;

if (!theDefault.empty())
	theName = theName + " = " + theDefault;

return theName;
