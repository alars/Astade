wxTreeItemId aID = GetRootItem();
bool found;

do
{
	found = false;
	wxTreeItemIdValue cookie;

	if (!GetFirstChild(aID,cookie).IsOk())
		LoadSubnodes(aID);

	wxTreeItemId search = GetFirstChild(aID,cookie);

	while (search.IsOk() && !found)
	{
		wxFileName aFile = GetItem(search)->GetFileName();
		wxFileName aCopy(fileName);
		aCopy.MakeRelativeTo(aFile.GetPath());
		wxArrayString theDirs = aCopy.GetDirs();

		if ((theDirs.GetCount()==0)  && (aFile.GetFullName() == fileName.GetFullName()))
		{
			aID = search;
			SelectItem(aID);
			EnsureVisible(aID);
			return;
		}
		else
		if ((theDirs.GetCount()>0)  && (theDirs[0]!=".."))
		{
			aID = search;
			found = true;
		}
		else
		if ((theDirs.GetCount()==0)  && (ItemHasChildren(search)))
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