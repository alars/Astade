wxArrayString names;

names.Add("file");
names.Add("make");

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