wxArrayString names;

names.Add("operation");

wxString visibility = static_cast<AdeOperation*>(myModelElement)->GetVisibility();

if (visibility == "private")
	names.Add("private");
else if (visibility == "public")
	names.Add("public");
else if (visibility == "protected")
	names.Add("protected");

if (static_cast<AdeOperation*>(myModelElement)->IsConst())
	names.Add("const");

if (static_cast<AdeOperation*>(myModelElement)->IsStatic())
	names.Add("static");

if (static_cast<AdeOperation*>(myModelElement)->IsAbstract())
	names.Add("abstract");
else if (static_cast<AdeOperation*>(myModelElement)->IsVirtual())
	names.Add("virtual");

if (static_cast<AdeOperation*>(myModelElement)->IsInline())
	names.Add("inline");

if (search->isSet(AdeSearch::SearchIsActive))
{
	switch (myModelElement->Search(*search))
	{
		case AdeSearch::contain: names.Add("hasfound");break;
		case AdeSearch::found: names.Add("found");break;
		default: break;
	}
}
else
{
	if(myModelElement->IsUndocumented())
		names.Add("isundocumented");
	else if(myModelElement->ContainsUndocumented())
		names.Add("containundocumented");
}

if(static_cast<AdeOperation*>(myModelElement)->IsDeprecated())
	names.Add("deprecated");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
