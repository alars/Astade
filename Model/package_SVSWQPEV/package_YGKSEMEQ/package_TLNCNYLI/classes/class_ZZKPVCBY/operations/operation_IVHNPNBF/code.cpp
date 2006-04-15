wxTreeItemId aID = GetRootItem();
wxTreeItemIdValue cookie;
wxTreeItemId search;
wxTreeItemId result;

//if (!IsExpanded(aID))
//	Expand(aID);

search = GetFirstChild(aID,cookie);

while (search.IsOk());
{
//	wxFileName aFile = GetItem(search)->GetFileName();
//	wxFileName aCopy(fileName);
//	aCopy.MakeRelativeTo(aFile.GetPath());
//	wxLogMessage(aCopy.GetFullPath());
//	if (aCopy.GetDirs()[0]!="..")
//		result = search;
	search = GetNextChild(aID,cookie);
}
//aID = result;

//SelectItem(aID);
//EnsureVisible(aID);
