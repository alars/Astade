wxArrayString names;

names.Add("attribute");

wxString visibility = static_cast<AdeAttribute*>(myModelElement)->GetVisibility();

if (visibility == "private")
	names.Add("private");
else if (visibility == "public")
	names.Add("public");
else if (visibility == "protected")
	names.Add("protected");

if (static_cast<AdeAttribute*>(myModelElement)->IsConst())
	names.Add("const");

if (static_cast<AdeAttribute*>(myModelElement)->IsStatic())
	names.Add("static");

if (search->isSet(AdeSearch::SearchIsActive))
{
	if (myModelElement->Search(*search) == AdeSearch::found)
		names.Add("found");
}
else
{
	if(myModelElement->IsUndocumented())
		names.Add("isundocumented");
	else if(myModelElement->ContainsUndocumented())
		names.Add("containundocumented");
}

if(static_cast<AdeAttribute*>(myModelElement)->IsDeprecated())
	names.Add("deprecated");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
