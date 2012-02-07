//~~ int GetIconIndex() [AstadeState] ~~

wxArrayString names;

names.Add(wxS("state"));

if (search->isSet(AdeSearch::SearchIsActive))
{
	switch (myModelElement->Search(*search))
	{
		case AdeSearch::contain: names.Add(wxS("hasfound"));break;
		case AdeSearch::found: names.Add(wxS("found"));break;
		default: break;
	}
}
else
{
	if (myModelElement->IsUndocumented())
		names.Add(wxS("isundocumented"));
	else if (myModelElement->ContainsUndocumented())
		names.Add(wxS("containundocumented"));
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
