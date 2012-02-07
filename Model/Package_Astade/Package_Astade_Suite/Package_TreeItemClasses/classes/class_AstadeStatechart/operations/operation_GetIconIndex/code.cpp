//~~ int GetIconIndex() [AstadeStatechart] ~~

wxArrayString names;

names.Add(wxS("class"));
names.Add(wxS("statechart"));

if (static_cast<AdeClass*>(myModelElement)->IsInActiveComponent())
{
	if (static_cast<AdeClass*>(myModelElement)->GetImpGenerationTime() >= static_cast<AdeClass*>(myModelElement)->GetModificationTime())
		names.Add(wxS("belonging"));
	else
		names.Add(wxS("changed"));
}

if (search->isSet(AdeSearch::SearchIsActive))
{
	switch (myModelElement->Search(*search))
	{
	case AdeSearch::contain:
		names.Add(wxS("hasfound"));
		break;
	case AdeSearch::found:
		names.Add(wxS("found"));
		break;
	default:
		break;
	}
}
else
{
	if(myModelElement->IsUndocumented())
		names.Add(wxS("isundocumented"));
	else if(myModelElement->ContainsUndocumented())
		names.Add(wxS("containundocumented"));
}

if (static_cast<AdeClass*>(myModelElement)->IsTraced())
    names.Add(wxS("traced"));

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
