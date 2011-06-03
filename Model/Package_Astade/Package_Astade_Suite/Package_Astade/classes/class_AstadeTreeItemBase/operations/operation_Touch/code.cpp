//~~ void Touch() [AstadeTreeItemBase] ~~

assert(ourTree);

wxTreeItemId anItem = GetId();

while (anItem.IsOk())
{
	AstadeTreeItemBase* theData = dynamic_cast<AstadeTreeItemBase*>(ourTree->GetItemData(anItem));
	if (theData)
	{
		assert(theData->myModelElement);
		
		theData->myModelElement->Touch();
		theData->SetNeedUpdate();		
	}
	anItem = ourTree->GetItemParent(anItem);
}
