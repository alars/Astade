wxTreeItemId aID = myTree->GetSelection();
AdeModelElement* element = myTree->GetItem(aID);

int type = element->GetType(); //Get the item type
if ((type & ITEM_TYPE_MASK) ==  ITEM_IS_MODEL || (type & ITEM_TYPE_MASK) == ITEM_IS_PACKAGE)
{
	wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

	wxFileName theNewPackage = AdePackage::CreateNewElement(parentPath);
	UpdateSubtree(aID);
	myTree->ShowNode(theNewPackage);
}