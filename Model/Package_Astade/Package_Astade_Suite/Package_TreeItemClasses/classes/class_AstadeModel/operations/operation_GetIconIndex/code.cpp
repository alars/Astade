wxArrayString names;

names.Add("model");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;