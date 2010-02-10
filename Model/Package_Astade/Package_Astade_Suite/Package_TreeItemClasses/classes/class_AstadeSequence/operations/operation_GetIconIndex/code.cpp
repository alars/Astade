wxArrayString names;

names.Add("sequence");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
