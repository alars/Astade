wxTreeItemId aID = myTree->GetSelection();
AdeModelElement* element = myTree->GetItem(aID);

int type = element->GetType(); //Get the item type
if ((type & ITEM_TYPE_MASK) == ITEM_IS_CLASSES)
{
	wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

	wxFileName theClass = AdeClass::CreateNewElement(parentPath);

	if (event.GetId()==ID_ADDLIBCLASS || AddLibClassOn)
	{
		AdeClass(theClass).SetIsLibClass();
		AddLibClassOn =false; //Set back to the default value for the next AddClass operation.
	}

	UpdateSubtree(aID);
	myTree->ShowNode(theClass);
}