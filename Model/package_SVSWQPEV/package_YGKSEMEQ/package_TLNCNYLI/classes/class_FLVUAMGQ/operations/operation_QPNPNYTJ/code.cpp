wxTreeItemId aItem = GetId();

while (aItem.IsOk())
{
	AstadeTreeItemBase* theData = dynamic_cast<AstadeTreeItemBase*>(ourTree->GetItemData(aItem));
	if (theData)
	{
		theData->myModelElement->Touch();
		theData->SetNeedUpdate();
		aItem = ourTree->GetItemParent(aItem);
	}
}