wxString theName = myConfig->Read(wxS("Astade/Name"));
wxString theCodingType = myConfig->Read(wxS("Astade/CodingType"));
wxString theDefault = myConfig->Read(wxS("Astade/Default"));

if (!theCodingType.empty())
	theName = theCodingType + wxS(" ") + theName;

if (!theDefault.empty())
	theName = theName + wxS(" = ") + theDefault;

return theName;
