//~~ int GetIconIndex() [AstadeUsecaseDiagrams] ~~

wxArrayString names;

names.Add(wxS("folder"));
names.Add(wxS("usecasediagram"));

assert(!myModelElement->IsUndocumented());
assert(!myModelElement->ContainsUndocumented());
	
int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
