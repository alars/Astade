//~~ int GetIconIndex() [AstadePackage] ~~

wxArrayString names;
names.Add(wxS("package"));

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
	if (myModelElement->IsUndocumented())
		names.Add(wxS("isundocumented"));
	else if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->ContainsUndocumented())
		names.Add(wxS("containundocumented"));
}

AdePackage* me = dynamic_cast<AdePackage*>(myModelElement);

if (me && me->isNamespace())
    names.Add(wxS("namespace"));

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
