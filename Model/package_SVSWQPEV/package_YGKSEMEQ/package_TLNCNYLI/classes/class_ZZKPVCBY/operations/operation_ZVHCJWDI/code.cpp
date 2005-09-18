wxTreeItemId aId = GetRootItem();

while (aId.IsOk())
{
	UpdateItem(aId);
	aId = GetNextVisible(aId);
}