wxTreeItemId aID = GetRootItem();
bool found;

do
{
	found = false;

	if (!IsExpanded(aID))
		Expand(aID);

	wxTreeItemIdValue cookie;
	wxTreeItemId search;

	search = GetFirstChild(aID,cookie);

	while (search.IsOk() && !found)
	{
		wxFileName aFile = GetItem(search)->GetFileName();
		wxFileName aCopy(fileName);
		aCopy.MakeRelativeTo(aFile.GetPath());
		wxArrayString theDirs = aCopy.GetDirs();
		if (((theDirs.GetCount()>0)  && (theDirs[0]!="..")) ||
			((theDirs.GetCount()==0) && (aFile.GetFullName() == fileName.GetFullName())))
		{
			aID = search;
			found = true;
		}
		else
			search = GetNextChild(aID,cookie);
	}
	SelectItem(aID);
} while (found);

EnsureVisible(aID);