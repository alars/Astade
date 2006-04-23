/* vi: set tabstop=4: */

AdeDirectoryElement* aDir = dynamic_cast<AdeDirectoryElement*>(GetItem(aID));

if (aDir==NULL)
	return;

wxTreeItemIdValue cookie;
if (GetFirstChild(aID,cookie).IsOk())
	return; // if already has children, do nothing.


AdeElementIterator iter;
for (iter = aDir->begin(); iter != aDir->end(); ++iter)
{
	AdeModelElement* aElement = iter.CreateNewElement();

	if ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_INRELATION)
	{
		if (dynamic_cast<AdeRelationBase*>(aElement)->PartnerExists())
		{
			wxTreeItemId newItem = AppendItem(aID,"loading ...", 48);
			SetItem(newItem,aElement);
			UpdateItem(newItem);
		}
		else
		{
			aElement->Delete();
			delete aElement;
		}
	}
	else
	{
		wxTreeItemId newItem = AppendItem(aID,"loading ...", 48);
		SetItem(newItem,aElement);
		UpdateItem(newItem);
	}
}

SortChildren(aID);