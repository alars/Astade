//~~ int GetIconIndex() [AstadeUseCase] ~~

wxArrayString names;

names.Add(wxS("usecasediagram"));

assert(!myModelElement->IsUndocumented());

if(myModelElement->ContainsUndocumented())
	names.Add(wxS("containundocumented"));	
	
int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
