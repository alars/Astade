/* vi: set tabstop=4: */

wxString theName(myConfig->Read("Astade/Name"));
wxString theCodingType(myConfig->Read("Astade/CodingType"));
wxString aDefault(myConfig->Read("Astade/Default"));

if (!theCodingType.empty())
	theName = theCodingType + " " + theName;
if (!aDefault.empty())
	theName += " = " + aDefault;

return theName;