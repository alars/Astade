//~~ wxTreeItemId ShowNode(wxFileName fileName) [AstadeTree] ~~

wxTreeItemId anID = GetRootItem();
bool found;

do
{
	found = false;
	wxTreeItemIdValue cookie;

	if (!GetFirstChild(anID, cookie).IsOk())
		LoadSubnodes(anID);

	wxTreeItemId search = GetFirstChild(anID,cookie);

	while (search.IsOk() && !found)
	{
		wxFileName aFile = GetItem(search)->GetFileName();
		wxFileName aCopy(fileName);
		aCopy.MakeRelativeTo(aFile.GetPath());
		wxArrayString theDirs = aCopy.GetDirs();

		if (theDirs.GetCount() == 0 && aFile.GetFullName() == fileName.GetFullName())
		{
			anID = search;
			SelectItem(anID);
			EnsureVisible(anID);
			return anID;
		}
		else if (theDirs.GetCount() > 0 && theDirs[0] != "..")
		{
			anID = search;
			found = true;
		}
		else if (theDirs.GetCount() == 0 && dynamic_cast<AdeDirectoryElement*>(GetItem(search)))
		{
			anID = search;
			found = true;
		}
		else
			search = GetNextChild(anID, cookie);
	}
} while (found);

SelectItem(anID);
EnsureVisible(anID);
return anID;
