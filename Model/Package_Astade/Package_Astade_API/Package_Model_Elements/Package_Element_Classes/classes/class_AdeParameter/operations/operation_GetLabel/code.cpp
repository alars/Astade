wxString theName(myConfig->Read(wxS("Astade/Name")));
wxString theCodingType(myConfig->Read(wxS("Astade/CodingType")));
wxString aDefault(myConfig->Read(wxS("Astade/Default")));

if (!theCodingType.empty())
	theName = theCodingType + wxS(" ") + theName;
if (!aDefault.empty())
	theName += wxS(" = ") + aDefault;

return theName;
