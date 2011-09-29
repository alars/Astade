//~~ void UpdateItem(const wxTreeItemId& theID) [AstadeTree] ~~
if (theID.IsOk())
	GetItemObject(theID)->SetNeedUpdate();