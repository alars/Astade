wxArrayString names;

names.Add("loading");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
