//~~ int GetIconIndex() [AstadeConstructor] ~~

wxArrayString names;

names.Add("operation");
names.Add("constructor");

wxString visibility = static_cast<AdeConstructor*>(myModelElement)->GetVisibility();

if (visibility == "private")
	names.Add("private");
else if (visibility == "public")
	names.Add("public");
else if (visibility == "protected")
	names.Add("protected");

if (static_cast<AdeConstructor*>(myModelElement)->IsInline())
{
	names.Add("inline");
}
else if (static_cast<AdeConstructor*>(myModelElement)->GetTraceLevel())
{
    AdeModelElement* anElement = myModelElement->GetGrandParent();
    AdeClass* aClass = dynamic_cast<AdeClass*>(anElement);
	if (aClass && aClass->IsTraced())
        names.Add("tracable");
    delete anElement;
}

if (search->isSet(AdeSearch::SearchIsActive))
{
	switch (myModelElement->Search(*search))
	{
		case AdeSearch::contain:
			names.Add("hasfound");
			break;
		case AdeSearch::found:
			names.Add("found");
			break;
		default:
			break;
	}
}
else if (myModelElement->IsUndocumented())
	names.Add("isundocumented");
else if (myModelElement->ContainsUndocumented())
	names.Add("containundocumented");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
