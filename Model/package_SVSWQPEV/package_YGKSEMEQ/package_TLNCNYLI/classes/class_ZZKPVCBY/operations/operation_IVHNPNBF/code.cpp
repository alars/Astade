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
		if (aCopy.GetDirs()[0]!="..")
		{
			aID = search;
			found = true;
		}
		else
			search = GetNextChild(aID,cookie);
	}
} while (found);

SelectItem(aID);
EnsureVisible(aID);