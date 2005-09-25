wxDateTime lastModified = AdeModelElement::GetModificationTime();

AdeElementIterator it;

for (it=begin();it!=end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	wxDateTime aModified = aElement->GetModificationTime();

	if (aModified > lastModified)
		lastModified = aModified;
	delete aElement;
}

return lastModified;
