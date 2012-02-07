//~~ int GetIconIndex() [AstadeModel] ~~

wxArrayString names;

names.Add(wxS("model"));

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
