//~~ void UpdateAll(const wxTreeItemId& ID) [AstadeTree] ~~

wxTreeItemIdValue  cookie;
wxTreeItemId anId = GetFirstChild(ID, cookie);

while (anId.IsOk())
{
	UpdateItem(anId);
	UpdateAll(anId);
	anId = GetNextChild(ID, cookie);
}
