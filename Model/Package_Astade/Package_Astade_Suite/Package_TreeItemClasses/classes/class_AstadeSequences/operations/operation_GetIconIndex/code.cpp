//~~ int GetIconIndex() [AstadeSequences] ~~

wxArrayString names;

names.Add(wxS("folder"));
names.Add(wxS("sequence"));

assert(!myModelElement->IsUndocumented());

if(myModelElement->ContainsUndocumented())
	names.Add(wxS("containundocumented"));
	
int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
