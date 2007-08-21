wxTreeItemId aItem = GetId();

while (aItem.IsOk())
{
	AstadeTreeItemBase* theData = dynamic_cast<AstadeTreeItemBase*>(ourTree->GetItemData(aItem));
	if (theData)
	{
		theData->myModelElement->Touch();
		aItem = ourTree->GetItemParent(aItem);
	}
}

AstadeTreeItemBase* theData = dynamic_cast<AstadeTreeItemBase*>(ourTree->GetItemData(GetId()));
if (theData)
	theData->SetNeedUpdate();