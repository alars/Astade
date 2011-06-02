//~~ void LoadSubnodes(wxTreeItemId anID) [AstadeTree] ~~

AdeDirectoryElement* aDir = dynamic_cast<AdeDirectoryElement*>(GetItem(anID));

if (aDir == NULL)
	return;

wxTreeItemIdValue cookie;
if (GetFirstChild(anID, cookie).IsOk())
	return; // if already has children, do nothing.

for (AdeElementIterator iter = aDir->begin(); iter != aDir->end(); ++iter)
{
	AdeModelElement* anElement = iter.CreateNewElement();
	AdeInRelation* anInRelation = dynamic_cast<AdeInRelation*>(anElement);

	if (anInRelation)
	{
		if (anInRelation->PartnerExists())
		{
			wxTreeItemId newItem = AppendExistingItem(anID,iter.GetFileName());
			UpdateItem(newItem);
		}
		else
		{
			anElement->Delete();
		}
	}
	else
	{
		wxTreeItemId newItem = AppendExistingItem(anID,iter.GetFileName());
		UpdateItem(newItem);
	}
	delete anElement;
}

SortChildren(anID);
