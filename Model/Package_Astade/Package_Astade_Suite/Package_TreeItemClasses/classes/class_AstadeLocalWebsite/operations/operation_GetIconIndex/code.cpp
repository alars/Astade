//~~ int GetIconIndex() [AstadeLocalWebsite] ~~

wxArrayString names;

names.Add(wxS("website"));

assert(!myModelElement->IsUndocumented());
assert(!myModelElement->ContainsUndocumented());
	
int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
