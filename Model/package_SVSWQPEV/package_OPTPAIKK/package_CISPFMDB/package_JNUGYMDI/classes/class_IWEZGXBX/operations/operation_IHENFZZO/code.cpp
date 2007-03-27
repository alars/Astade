wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

std::list<wxString> aList;
wxString aString;

aString = theConfig.Read("Astade/Action1");
if (!aString.empty())
	aList.insert(aList.end(),aString);

aString = theConfig.Read("Astade/Action2");
if (!aString.empty())
	aList.insert(aList.end(),aString);

aString = theConfig.Read("Astade/Action3");
if (!aString.empty())
	aList.insert(aList.end(),aString);

aString = theConfig.Read("Astade/Action4");
if (!aString.empty())
	aList.insert(aList.end(),aString);

return aList;