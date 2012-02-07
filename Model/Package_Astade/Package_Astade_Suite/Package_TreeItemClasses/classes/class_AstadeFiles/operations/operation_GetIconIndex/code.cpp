//~~ int GetIconIndex() [AstadeFiles] ~~

wxArrayString names;

names.Add(wxS("folder"));
names.Add(wxS("file"));

wxString label = static_cast<AdeFiles*>(myModelElement)->GetLabel();

if (label == wxS("manual"))
	names.Add(wxS("manual"));

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
