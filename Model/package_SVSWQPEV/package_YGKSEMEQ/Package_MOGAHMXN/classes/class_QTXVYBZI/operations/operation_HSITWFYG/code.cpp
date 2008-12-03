wxArrayString names;

names.Add("model");

assert(myModelElement->IsUndocumented()==false);
assert(myModelElement->ContainsUndocumented()==false);
	
int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;