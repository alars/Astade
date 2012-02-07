//~~ void StoreAllExpanded(const wxTreeItemId& ID) [AstadeTree] ~~

wxTreeItemIdValue  cookie;
wxTreeItemId anId = GetFirstChild(ID,cookie);
wxConfigBase* theConfig = wxConfigBase::Get();

while (anId.IsOk())
{
	AdeDirectoryElement* aDir = dynamic_cast<AdeDirectoryElement*>(GetItem(anId));
	if (aDir)
	{
		if (IsExpanded(anId))
		{
			theConfig->Write(wxS("ExpandedNodes/") + aDir->GetGUID(), true);
			StoreAllExpanded(anId);
		}
	}
	anId = GetNextChild(ID, cookie);
}
