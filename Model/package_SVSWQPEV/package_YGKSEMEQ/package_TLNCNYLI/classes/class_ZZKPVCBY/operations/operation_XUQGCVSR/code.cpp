AdeModelElement* theElement = GetItem(theID);

if (theElement)
{
	SetItemImage(theID,theElement->GetIconIndex());
	SetItemText(theID,theElement->GetLabel());
	SetItemHasChildren(theID,theElement->GetHasChildren());
}