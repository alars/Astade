//~~ int GetIconIndex() [AstadePackage] ~~
wxArrayString names;
names.Add("package");

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
	else if(dynamic_cast<AdeDirectoryElement*>(myModelElement)->ContainsUndocumented())
		names.Add("containundocumented");
}

AdePackage* me = dynamic_cast<AdePackage*>(myModelElement);

if (me && me->isNamespace())
    names.Add("namespace");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;