wxArrayString names;

names.Add("state");

if(myModelElement->IsUndocumented())
	names.Add("isundocumented");
else if(myModelElement->ContainsUndocumented())
	names.Add("containundocumented");	
	
int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;