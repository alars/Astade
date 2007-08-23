if (static_cast<AdeComponent*>(myModelElement)->IsActiveComponent())
{
	AdeElementIterator it;
	for (it = static_cast<AdeComponent*>(myModelElement)->GetFirstBelongingClass(); it != static_cast<AdeComponent*>(myModelElement)->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		AdeClass* aClass = dynamic_cast<AdeClass*>(anElement);
		if (aClass)
		{
			if (aClass->GetModificationTime() > aClass->GetImpGenerationTime())
				return 69;
		}
		delete anElement;
	}

	for (it = static_cast<AdeComponent*>(myModelElement)->GetFirstBelongingStatechart(); it != static_cast<AdeComponent*>(myModelElement)->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		AdeClass* aClass = dynamic_cast<AdeClass*>(anElement);
		if (aClass)
		{
			if (aClass->GetModificationTime() > aClass->GetImpGenerationTime())
				return 69;
		}
		delete anElement;
	}

	return 42;
}
else
	return 6;