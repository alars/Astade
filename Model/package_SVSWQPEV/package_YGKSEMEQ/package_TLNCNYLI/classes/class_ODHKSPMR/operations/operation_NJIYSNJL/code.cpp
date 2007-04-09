wxConfigBase* theConfig = wxConfigBase::Get();

std::list<wxString> aList;

wxString aString;

aList.push_back(filename.GetFullPath());

if (theConfig->Read("TreeView/Recent_1", &aString, wxEmptyString) && (aString != filename.GetFullPath()))
	aList.push_back(aString);

if (theConfig->Read("TreeView/Recent_2", &aString, wxEmptyString) && (aString != filename.GetFullPath()))
	aList.push_back(aString);

if (theConfig->Read("TreeView/Recent_3", &aString, wxEmptyString) && (aString != filename.GetFullPath()))
	aList.push_back(aString);

if (theConfig->Read("TreeView/Recent_4", &aString, wxEmptyString) && (aString != filename.GetFullPath()) && (aList.size() < 4))
	aList.push_back(aString);

std::list<wxString>::iterator it = aList.begin();

if (it != aList.end())
	theConfig->Write("TreeView/Recent_1", *it++);

if (it != aList.end())
	theConfig->Write("TreeView/Recent_2", *it++);

if (it != aList.end())
	theConfig->Write("TreeView/Recent_3", *it++);

if (it != aList.end())
	theConfig->Write("TreeView/Recent_4", *it++);

AddRecentList();