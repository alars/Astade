//~~ int GetIconIndex() [AstadeFiles] ~~
wxArrayString names;

names.Add("folder");
names.Add("file");

wxString label = static_cast<AdeFiles*>(myModelElement)->GetLabel();

if (label == "manual")
	names.Add("manual");

if (label == "diagrams")
	names.Add("diagram");

if (search->isSet(AdeSearch::SearchIsActive))
{
	switch (myModelElement->Search(*search))
	{
		case AdeSearch::contain: names.Add("hasfound");break;
		case AdeSearch::found: names.Add("found");break;
		default: break;
	}
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
