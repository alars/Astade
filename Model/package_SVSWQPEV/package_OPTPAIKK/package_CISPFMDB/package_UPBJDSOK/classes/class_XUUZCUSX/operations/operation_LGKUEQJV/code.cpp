wxDateTime lastModified = AdeModelElement::GetModificationTime();

AdeElementIterator it;

for (it = begin(); it != end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	wxDateTime aModified = aElement->GetModificationTime();

	if (((aElement->GetType() & ITEM_TYPE_MASK) != ITEM_IS_INRELATION) && (aModified > lastModified))
		lastModified = aModified;
	delete aElement;
}

return lastModified;
