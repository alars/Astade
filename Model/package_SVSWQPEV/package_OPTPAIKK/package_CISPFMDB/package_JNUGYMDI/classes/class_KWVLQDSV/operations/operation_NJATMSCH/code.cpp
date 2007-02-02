if (IsActiveComponent())
{
	AdeElementIterator it;
	for (it = GetFirstBelongingClass(); it != end(); ++it)
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

	for (it = GetFirstBelongingStatechart(); it != end(); ++it)
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