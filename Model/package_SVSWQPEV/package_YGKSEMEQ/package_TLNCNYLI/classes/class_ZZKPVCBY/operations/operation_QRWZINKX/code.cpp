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
	AdeInRelation* aInRelation = dynamic_cast<AdeInRelation*>(aElement);

	if (aInRelation)
	{
		if (aInRelation->PartnerExists())
		{
			wxTreeItemId newItem = AppendExistingItem(aID,iter.GetFileName());
			UpdateItem(newItem);
		}
		else
		{
			aElement->Delete();
		}
	}
	else
	{
		wxTreeItemId newItem = AppendExistingItem(aID,iter.GetFileName());
		UpdateItem(newItem);
	}
	delete aElement;
}

SortChildren(aID);