wxArrayString names;
names.Add("package");

if(myModelElement->IsUndocumented())
	names.Add("isundocumented");
else if(dynamic_cast<AdeDirectoryElement*>(myModelElement)->ContainsUndocumented())
	names.Add("containundocumented");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;