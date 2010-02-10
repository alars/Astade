wxConfigBase* theConfig = wxConfigBase::Get();

wxTreeItemIdValue cookie;
wxTreeItemId search = GetFirstChild(ID,cookie);

while (search.IsOk())
{
	AdeDirectoryElement* aDir = dynamic_cast<AdeDirectoryElement*>(GetItem(search));
	if (aDir && (theConfig->Exists("ExpandedNodes/"+aDir->GetGUID())))
	{
		LoadSubnodes(search);
		Expand(search);
		LoadExpansion(search);
	}
	search = GetNextChild(ID,cookie);
}
