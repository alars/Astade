wxArrayString names;

names.Add("file");

wxFileName aName = myModelElement->GetFileName();

if (aName.GetExt()=="cpp")
	names.Add("cpp");
else if (aName.GetExt()=="h")
	names.Add("h");
else if (aName.GetExt()=="dox")
	names.Add("doxygen");
else if (aName.GetExt()=="c")
	names.Add("c");

wxDateTime access,mod,create;
aName.GetTimes(&access,&mod,&create);

if (aName.GetDirs().Last() == "auto")
    if (mod > create)
		names.Add("attention");

assert(myModelElement->IsUndocumented()==false);

assert(myModelElement->ContainsUndocumented()==false);

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;

