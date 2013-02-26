//~~ void operation() [AdeElementIterator] ~~
// theFilenameList ist std::list mit wxFileName

std::list<wxString> sortList;

do
{
	std::list<wxFileName>::iterator it;

	for (it = theFilenameList.begin(); it != theFilenameList.end(); ++it)
	{
		wxString	str(it->GetFullPath());
		sortList.push_back(str);
	}
} while (0);

sortList.sort();		// sort by name
theFilenameList.clear();	// clear list

std::list<wxString>::iterator it;
for (it = sortList.begin(); it != sortList.end(); ++it)
{
	wxFileName aNewFileName(*it);
	theFilenameList.push_back(aNewFileName);
}
