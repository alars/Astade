wxTreeItemIdValue  cookie;
wxTreeItemId aId = GetFirstChild(ID,cookie);
wxConfigBase* theConfig = wxConfigBase::Get();

while (aId.IsOk())
{
	AdeDirectoryElement* aDir = dynamic_cast<AdeDirectoryElement*>(GetItem(aId));
	if (aDir)
	{
		if (IsExpanded(aId))
		{
			theConfig->Write("ExpandedNodes/"+aDir->GetGUID(),true);
			StoreAllExpanded(aId);
		}
		aId = GetNextChild(ID,cookie);
	}
}