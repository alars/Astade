/* vi: set tabstop=4: */

wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());

wxString theName(theConfig.Read("Astade/Name"));
wxString theCodingType(theConfig.Read("Astade/CodingType"));
wxString aDefault(theConfig.Read("Astade/Default"));

if (!theCodingType.empty())
	theName = theCodingType + " " + theName;
if (!aDefault.empty())
	theName += " = " + aDefault;

return theName;
