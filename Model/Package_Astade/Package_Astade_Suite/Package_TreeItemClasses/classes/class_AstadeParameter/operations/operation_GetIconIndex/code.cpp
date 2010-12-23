//~~ int GetIconIndex() [AstadeParameter] ~~
wxArrayString names;

names.Add("parameter");

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
	else if(myModelElement->ContainsUndocumented())
		names.Add("containundocumented");
}

AdeParameter* me = dynamic_cast<AdeParameter*>(myModelElement);

if (me)
{
	bool isInput = me->IsInput();
	bool isOutput = me->IsOutput();

	if (isInput && isOutput)
		names.Add("inoutparameter");
	else if (isInput)
		names.Add("inputparameter");
	else if (isOutput)
		names.Add("outputparameter");
}

if (!myModelElement->GetConstraint().empty())
		names.Add("constraint");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
