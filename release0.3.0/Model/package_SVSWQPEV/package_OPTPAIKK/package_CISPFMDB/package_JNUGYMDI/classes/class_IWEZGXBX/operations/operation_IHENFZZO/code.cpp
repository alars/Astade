wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

std::set<wxString> aSet;
wxString aString;

aString = theConfig.Read("Astade/Action1");
if (!aString.empty())
	aSet.insert(aString);

aString = theConfig.Read("Astade/Action2");
if (!aString.empty())
	aSet.insert(aString);

aString = theConfig.Read("Astade/Action3");
if (!aString.empty())
	aSet.insert(aString);

aString = theConfig.Read("Astade/Action4");
if (!aString.empty())
	aSet.insert(aString);

return aSet;