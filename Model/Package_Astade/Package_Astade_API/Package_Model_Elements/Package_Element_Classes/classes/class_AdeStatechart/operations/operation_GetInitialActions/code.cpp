std::set<wxString> aSet;
wxString aString;

aString = myConfig->Read("Astade/Action1");
if (!aString.empty())
	aSet.insert(aString);

aString = myConfig->Read("Astade/Action2");
if (!aString.empty())
	aSet.insert(aString);

aString = myConfig->Read("Astade/Action3");
if (!aString.empty())
	aSet.insert(aString);

aString = myConfig->Read("Astade/Action4");
if (!aString.empty())
	aSet.insert(aString);

return aSet;