//~~ int GetIconIndex() [AstadePorts] ~~

wxArrayString names;

names.Add(wxS("folder"));
names.Add(wxS("port"));

assert(!myModelElement->IsUndocumented());

if (search->isSet(AdeSearch::SearchIsActive))
{
	if (myModelElement->Search(*search) == AdeSearch::contain)
		names.Add(wxS("hasfound"));
}
else
{
	if (myModelElement->ContainsUndocumented())
		names.Add(wxS("containundocumented"));
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
