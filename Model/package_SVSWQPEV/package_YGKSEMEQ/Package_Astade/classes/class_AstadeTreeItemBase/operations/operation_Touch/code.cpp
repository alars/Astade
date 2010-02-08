assert(ourTree);

wxTreeItemId aItem = GetId();

while (aItem.IsOk())
{
	AstadeTreeItemBase* theData = dynamic_cast<AstadeTreeItemBase*>(ourTree->GetItemData(aItem));
	if (theData)
	{
		assert(theData->myModelElement);
		
		theData->myModelElement->Touch();
		theData->SetNeedUpdate();		
	}
	aItem = ourTree->GetItemParent(aItem);
}