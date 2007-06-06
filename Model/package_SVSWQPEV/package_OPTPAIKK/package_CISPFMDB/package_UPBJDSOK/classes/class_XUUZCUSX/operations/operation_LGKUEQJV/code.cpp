wxDateTime lastModified = AdeModelElement::GetModificationTime();

AdeElementIterator it;

for (it = begin(); it != end(); ++it)
{
	AdeModelElement* aElement = it.CreateNewElement();

	if (aElement->GetFileName().GetName().Find("inrelation_") == -1)
	{
		wxDateTime aModified = aElement->GetModificationTime();
		if (aModified > lastModified)
			lastModified = aModified;
	}

	delete aElement;
}


return lastModified;