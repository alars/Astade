//~~ int GetIconIndex() [AstadeSequence] ~~

wxArrayString names;

names.Add(wxS("sequence"));

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
