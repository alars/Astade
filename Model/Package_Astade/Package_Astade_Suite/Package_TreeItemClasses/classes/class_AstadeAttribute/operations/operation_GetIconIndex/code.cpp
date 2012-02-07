//~~ int GetIconIndex() [AstadeAttribute] ~~

wxArrayString names;

names.Add(wxS("attribute"));

wxString visibility = static_cast<AdeAttribute*>(myModelElement)->GetVisibility();

if (visibility == wxS("private") || visibility == wxS("public") || visibility == wxS("protected"))
	names.Add(visibility);

if (static_cast<AdeAttribute*>(myModelElement)->IsConst())
	names.Add(wxS("const"));

if (static_cast<AdeAttribute*>(myModelElement)->IsStatic())
	names.Add(wxS("static"));

if (search->isSet(AdeSearch::SearchIsActive))
{
	if (myModelElement->Search(*search) == AdeSearch::found)
		names.Add(wxS("found"));
}
else
{
	if (myModelElement->IsUndocumented())
		names.Add(wxS("isundocumented"));
	else if (myModelElement->ContainsUndocumented())
		names.Add(wxS("containundocumented"));
}

if (!myModelElement->GetConstraint().empty())
		names.Add(wxS("constraint"));

if (static_cast<AdeAttribute*>(myModelElement)->IsDeprecated())
	names.Add(wxS("deprecated"));

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
