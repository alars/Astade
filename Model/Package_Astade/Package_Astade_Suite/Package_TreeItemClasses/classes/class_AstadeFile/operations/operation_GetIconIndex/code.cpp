//~~ int GetIconIndex() [AstadeFile] ~~

wxArrayString names;

assert(!myModelElement->IsUndocumented());
assert(!myModelElement->ContainsUndocumented());

names.Add(wxS("user/") + myModelElement->GetFileName().GetExt());

int index = AstadeIcons::Instance()->GetIconIndex(names);

if (index < 0)
{
	names.Clear();
	names.Add(wxS("file"));
	index = AstadeIcons::Instance()->GetIconIndex(names);
}

assert(index >= 0);

return index;
