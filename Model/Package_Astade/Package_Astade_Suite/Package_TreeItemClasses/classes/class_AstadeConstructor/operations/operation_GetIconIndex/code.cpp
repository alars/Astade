//~~ int GetIconIndex() [AstadeConstructor] ~~

wxArrayString names;

names.Add(wxS("operation"));
names.Add(wxS("constructor"));

wxString visibility = static_cast<AdeConstructor*>(myModelElement)->GetVisibility();

if (visibility == wxS("private") || visibility == wxS("public") || visibility == wxS("protected"))
	names.Add(visibility);

if (static_cast<AdeConstructor*>(myModelElement)->IsInline())
{
	names.Add(wxS("inline"));
}
else if (static_cast<AdeConstructor*>(myModelElement)->GetTraceLevel())
{
    AdeModelElement* anElement = myModelElement->GetGrandParent();
    AdeClass* aClass = dynamic_cast<AdeClass*>(anElement);
	if (aClass && aClass->IsTraced())
        names.Add(wxS("tracable"));
    delete anElement;
}

if (search->isSet(AdeSearch::SearchIsActive))
{
	switch (myModelElement->Search(*search))
	{
	case AdeSearch::contain:
		names.Add(wxS("hasfound"));
		break;
	case AdeSearch::found:
		names.Add(wxS("found"));
		break;
	default:
		break;
	}
}
else if (myModelElement->IsUndocumented())
	names.Add(wxS("isundocumented"));
else if (myModelElement->ContainsUndocumented())
	names.Add(wxS("containundocumented"));

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
