//~~ int GetIconIndex() [AstadeParameter] ~~

wxArrayString names;

names.Add(wxS("parameter"));

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
	else if (myModelElement->ContainsUndocumented())
		names.Add(wxS("containundocumented"));
}

AdeParameter* me = dynamic_cast<AdeParameter*>(myModelElement);

if (me)
{
	bool isInput = me->IsInput();
	bool isOutput = me->IsOutput();

	if (isInput && isOutput)
		names.Add(wxS("inoutparameter"));
	else if (isInput)
		names.Add(wxS("inputparameter"));
	else if (isOutput)
		names.Add(wxS("outputparameter"));
}

if (!myModelElement->GetConstraint().empty())
		names.Add(wxS("constraint"));

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
