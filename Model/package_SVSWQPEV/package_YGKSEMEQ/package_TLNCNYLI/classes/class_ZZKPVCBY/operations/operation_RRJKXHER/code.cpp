wxTreeItemIdValue  cookie;
wxTreeItemId aId = GetFirstChild(ID,cookie);

while (aId.IsOk())
{
	UpdateItem(aId);
	UpdateAll(aId);
	aId = GetNextChild(ID,cookie);
}