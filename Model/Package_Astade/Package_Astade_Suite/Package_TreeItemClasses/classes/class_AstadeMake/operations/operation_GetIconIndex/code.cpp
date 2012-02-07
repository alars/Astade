//~~ int GetIconIndex() [AstadeMake] ~~

wxArrayString names;

names.Add(wxS("file"));
names.Add(wxS("make"));

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

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
