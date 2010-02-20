std::list<wxString> aList;
wxString aString;

aString = myConfig->Read("Astade/Action1");
if (!aString.empty())
	aList.push_back(aString);

aString = myConfig->Read("Astade/Action2");
if (!aString.empty())
	aList.push_back(aString);

aString = myConfig->Read("Astade/Action3");
if (!aString.empty())
	aList.push_back(aString);

aString = myConfig->Read("Astade/Action4");
if (!aString.empty())
	aList.push_back(aString);

return aList;
