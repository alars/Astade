//~~ int GetIconIndex() [AstadePort] ~~
wxArrayString names;

names.Add("connection");

if(myModelElement->IsUndocumented())
    names.Add("isundocumented");
else if(myModelElement->ContainsUndocumented())
    names.Add("containundocumented");

int index = AstadeIcons::Instance()->GetIconIndex(names);

return index;
