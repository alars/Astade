//~~ int GetIconIndex() [AstadePort] ~~
wxArrayString names;

AdePort* me = dynamic_cast<AdePort*>(myModelElement);

if (me)
{
	bool isDelegate = me->IsDelegate();

	names.Add("port");

    if (isDelegate)
        names.Add("delegate");
}

if (search->isSet(AdeSearch::SearchIsActive))
{
	if (myModelElement->Search(*search) == AdeSearch::found)
		names.Add("found");
}
else
{
	if(myModelElement->IsUndocumented())
		names.Add("isundocumented");
	else if(myModelElement->ContainsUndocumented())
		names.Add("containundocumented");
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

return index;
