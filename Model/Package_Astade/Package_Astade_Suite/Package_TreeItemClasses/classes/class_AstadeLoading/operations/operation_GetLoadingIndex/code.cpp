//~~ int GetLoadingIndex() [AstadeLoading] ~~

wxArrayString names;

names.Add(wxS("loading"));

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
