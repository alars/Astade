/* vi: set tabstop=4: */

wxTreeItemId aID = event.GetItem();
AdeDirectoryElement* aDir = dynamic_cast<AdeDirectoryElement*>(myTree->GetItem(aID));

AdeElementIterator iter;
for (iter = aDir->begin(); iter != aDir->end(); ++iter)
{
	AdeModelElement* aElement = iter.CreateNewElement();

	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_INRELATION)
	{
		if (dynamic_cast<AdeRelationBase*>(aElement)->PartnerExists())
		{
			wxTreeItemId newItem = myTree->AppendItem(aID,"loading ...", 48);
			myTree->SetItem(newItem,aElement);
			myTree->UpdateItem(newItem);
		}
		else
		{
			aElement->Delete();
			delete aElement;
		}
	}
	else
	{
		wxTreeItemId newItem = myTree->AppendItem(aID,"loading ...", 48);
		myTree->SetItem(newItem,aElement);
		myTree->UpdateItem(newItem);
	}
}

myTree->SortChildren(aID);
