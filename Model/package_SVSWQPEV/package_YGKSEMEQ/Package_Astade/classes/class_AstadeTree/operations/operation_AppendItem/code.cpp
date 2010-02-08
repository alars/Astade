if (GetChildrenCount(parent) > 0)
{
	wxTreeItemId newItem = AppendExistingItem(parent,element);
	EnsureVisible(newItem);
	GetItemObject(newItem)->Touch();
	SelectItem(newItem);
	return newItem;
}
else
{
	GetItemObject(parent)->Touch();
	SetItemHasChildren(parent);
	return ShowNode(element);
}