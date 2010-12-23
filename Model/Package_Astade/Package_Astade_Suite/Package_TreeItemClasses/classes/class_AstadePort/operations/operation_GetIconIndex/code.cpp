//~~ int GetIconIndex() [AstadePort] ~~
wxArrayString names;

AdePort* me = dynamic_cast<AdePort*>(myModelElement);

if (me)
{
	bool isInput = me->IsInput();
	bool isDelegate = me->IsDelegate();

	if (isInput)
		names.Add("inport");
    else
        names.Add("outport");

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
