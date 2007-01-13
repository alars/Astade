wxTreeItemId aID = myTree->GetSelection();
AdeModelElement* element = myTree->GetItem(aID);

int type = element->GetType(); //Get the item type
if ((type & ITEM_TYPE_MASK) == ITEM_IS_PACKAGE && !dynamic_cast<AdeDirectoryElement*>(element)->GetHasClasses())
{
	wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

	AdeClasses::CreateNewElement(parentPath);
	UpdateSubtree(aID);
}