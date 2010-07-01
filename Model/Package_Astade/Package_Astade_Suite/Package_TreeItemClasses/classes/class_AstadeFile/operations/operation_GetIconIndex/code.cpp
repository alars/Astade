//~~ int GetIconIndex() [AstadeFile] ~~
wxArrayString names;

assert(myModelElement->IsUndocumented()==false);
assert(myModelElement->ContainsUndocumented()==false);

names.Add("user/"+(myModelElement->GetFileName()).GetExt());

int index = AstadeIcons::Instance()->GetIconIndex(names);

if(index<0)
{
	names.Clear();
	names.Add("file");
	index = AstadeIcons::Instance()->GetIconIndex(names);
}

assert(index>=0);

return index;
