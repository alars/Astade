std::list<wxString> aList;
wxString aString;

aString = myConfig->Read(wxS("Astade/Action1"));
if (!aString.empty())
	aList.push_back(aString);

aString = myConfig->Read(wxS("Astade/Action2"));
if (!aString.empty())
	aList.push_back(aString);

aString = myConfig->Read(wxS("Astade/Action3"));
if (!aString.empty())
	aList.push_back(aString);

aString = myConfig->Read(wxS("Astade/Action4"));
if (!aString.empty())
	aList.push_back(aString);

return aList;
