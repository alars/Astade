//~~ int GetIconIndex() [AstadePort] ~~

wxArrayString names;

AdePort* me = dynamic_cast<AdePort*>(myModelElement);

if (me)
{
	bool isDelegate = me->IsDelegate();

	names.Add(wxS("port"));

    if (isDelegate)
        names.Add(wxS("delegate"));
}

if (search->isSet(AdeSearch::SearchIsActive))
{
	if (myModelElement->Search(*search) == AdeSearch::found)
		names.Add(wxS("found"));
}
else
{
	if (myModelElement->IsUndocumented())
		names.Add(wxS("isundocumented"));
	else if (myModelElement->ContainsUndocumented())
		names.Add(wxS("containundocumented"));
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

return index;
