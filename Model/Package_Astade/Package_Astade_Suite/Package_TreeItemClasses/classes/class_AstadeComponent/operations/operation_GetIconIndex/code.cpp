wxArrayString names;

names.Add("component");

if (static_cast<AdeComponent*>(myModelElement)->IsActiveComponent())
{
	bool isChanged = false;

	AdeElementIterator it;
	for (it = static_cast<AdeComponent*>(myModelElement)->GetFirstBelongingClass(); it != static_cast<AdeComponent*>(myModelElement)->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		AdeClass* aClass = dynamic_cast<AdeClass*>(anElement);
		isChanged |= (aClass && (aClass->GetModificationTime() > aClass->GetImpGenerationTime()));
		delete anElement;
	}

	for (it = static_cast<AdeComponent*>(myModelElement)->GetFirstBelongingStatechart(); it != static_cast<AdeComponent*>(myModelElement)->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		AdeClass* aClass = dynamic_cast<AdeClass*>(anElement);
		isChanged |= (aClass && (aClass->GetModificationTime() > aClass->GetImpGenerationTime()));
		delete anElement;
	}

	if(isChanged)
		names.Add("changed");
	else
		names.Add("belonging");
}

if (search->isSet(AdeSearch::SearchIsActive))
{
	switch (myModelElement->Search(*search))
	{
		case AdeSearch::contain: names.Add("hasfound");break;
		case AdeSearch::found: names.Add("found");break;
		default: break;
	}
}
else
{
	if(myModelElement->IsUndocumented())
		names.Add("isundocumented");
	else if(myModelElement->ContainsUndocumented())
		names.Add("containundocumented");
}

if (static_cast<AdeComponent*>(myModelElement)->useFramework())
	names.Add("framework");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
