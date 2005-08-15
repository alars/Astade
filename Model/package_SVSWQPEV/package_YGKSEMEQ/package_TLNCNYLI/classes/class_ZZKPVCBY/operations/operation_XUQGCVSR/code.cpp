AdeModelElement* theElement = GetItem(theID)->GetModelElement();

if (theElement)
{
	SetItemImage(theID,theElement->GetIconIndex());
	SetItemText(theID,theElement->GetLabel());
	SetItemHasChildren(theID,theElement->GetHasChildren());
}