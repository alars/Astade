//~~ int GetIconIndex() [AstadeComponents] ~~

wxArrayString names;

names.Add(wxS("folder"));
names.Add(wxS("component"));

assert(!myModelElement->IsUndocumented());

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
	if (myModelElement->ContainsUndocumented())
		names.Add(wxS("containundocumented"));
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
