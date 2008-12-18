wxArrayString names;

names.Add("parameter");

if(myModelElement->IsUndocumented())
	names.Add("isundocumented");
else if(myModelElement->ContainsUndocumented())
	names.Add("containundocumented");

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

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
