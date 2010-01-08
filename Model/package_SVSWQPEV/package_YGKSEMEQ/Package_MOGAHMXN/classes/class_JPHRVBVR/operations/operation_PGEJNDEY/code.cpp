wxArrayString names;

names.Add("class");
names.Add("statechart");

if (static_cast<AdeClass*>(myModelElement)->IsInActiveComponent())
{
	if (static_cast<AdeClass*>(myModelElement)->GetImpGenerationTime() >= static_cast<AdeClass*>(myModelElement)->GetModificationTime())
		names.Add("belonging");
	else
		names.Add("changed");
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

if (static_cast<AdeClass*>(myModelElement)->IsTraced())
    names.Add("traced");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
