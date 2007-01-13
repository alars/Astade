wxTreeItemId aID = myTree->GetSelection();

AdeModelElement* element = myTree->GetItem(aID);

int type = element->GetType(); //Get the item type
if ((type & ITEM_TYPE_MASK) == ITEM_IS_MODEL)
{
	wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

	AdeComponents::CreateNewElement(parentPath);
	UpdateSubtree(aID);
}