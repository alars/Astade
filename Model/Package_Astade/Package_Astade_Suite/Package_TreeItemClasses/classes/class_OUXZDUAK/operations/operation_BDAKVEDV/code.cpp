//~~ int GetIconIndex() [AstadePorts] ~~
wxArrayString names;

names.Add("folder");
names.Add("ports");

assert(myModelElement->IsUndocumented()==false);

if (search->isSet(AdeSearch::SearchIsActive))
{
	if (myModelElement->Search(*search) == AdeSearch::contain)
		names.Add("hasfound");
}
else
{
	if(myModelElement->ContainsUndocumented())
		names.Add("containundocumented");
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
