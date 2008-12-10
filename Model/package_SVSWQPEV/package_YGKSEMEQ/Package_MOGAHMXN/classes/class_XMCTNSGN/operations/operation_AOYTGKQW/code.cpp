wxArrayString names;

names.Add("class");

if (static_cast<AdeClass*>(myModelElement)->IsCCoded())
	names.Add("c");

if (static_cast<AdeClass*>(myModelElement)->IsLibClass())
	names.Add("lib");
else if (static_cast<AdeClass*>(myModelElement)->IsInActiveComponent())
{
	if (static_cast<AdeClass*>(myModelElement)->GetImpGenerationTime() >= static_cast<AdeClass*>(myModelElement)->GetModificationTime())
		names.Add("belonging");
	else
		names.Add("changed");
}

if(myModelElement->IsUndocumented())
	names.Add("isundocumented");
else if(myModelElement->ContainsUndocumented())
	names.Add("containundocumented");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
