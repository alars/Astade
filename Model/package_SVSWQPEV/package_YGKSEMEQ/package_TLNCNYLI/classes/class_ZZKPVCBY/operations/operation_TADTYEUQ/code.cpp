if (GetChildrenCount(parent) > 0)
{
	AdeModelElement* aElement = AdeModelElement::CreateNewElement(element);
	wxTreeItemId newItem = AppendItem(parent,"loading ...", 48);
	EnsureVisible(newItem);
	SetItem(newItem,aElement);
	GetItemObject(newItem)->Touch();
	SelectItem(newItem);
	return newItem;
}
else
{
	GetItemObject(parent)->Touch();
	ShowNode(element);
	return wxTreeItemId();
}