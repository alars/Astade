wxArrayString names;

names.Add("folder");
names.Add("file");

wxString label = static_cast<AdeFiles*>(myModelElement)->GetLabel();

if (label == "manual")
	names.Add("manual");
	
assert(myModelElement->IsUndocumented()==false);
assert(myModelElement->ContainsUndocumented()==false);

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
