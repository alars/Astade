//~~ wxTreeItemId AppendItem(const wxTreeItemId& parent, const wxFileName& element) [AstadeTree] ~~
if (GetChildrenCount(parent) > 0)
{
	wxTreeItemId newItem = AppendExistingItem(parent,element);
	EnsureVisible(newItem);
	GetItemObject(newItem)->Touch();
	SelectItem(newItem);
	
	FixOrderValues(newItem);
	
	return newItem;
}
else
{
	GetItemObject(parent)->Touch();
	SetItemHasChildren(parent);
	wxTreeItemId newItem = ShowNode(element);

	FixOrderValues(newItem);
	
	return newItem;
}
