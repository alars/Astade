//~~ int GetIconIndex() [AstadeConnection] ~~

wxArrayString names;

names.Add(wxS("connection"));

if (myModelElement->IsUndocumented())
    names.Add(wxS("isundocumented"));
else if (myModelElement->ContainsUndocumented())
    names.Add(wxS("containundocumented"));

int index = AstadeIcons::Instance()->GetIconIndex(names);

return index;
