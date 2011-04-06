//~~ int GetIconIndex() [AstadeDestructor] ~~

wxArrayString names;

names.Add("operation");
names.Add("destructor");

wxString visibility = static_cast<AdeDestructor*>(myModelElement)->GetVisibility();

if (visibility == "private")
	names.Add("private");
else if (visibility == "public")
	names.Add("public");
else if (visibility == "protected")
	names.Add("protected");

if (static_cast<AdeDestructor*>(myModelElement)->IsVirtual())
	names.Add("virtual");

if (static_cast<AdeDestructor*>(myModelElement)->IsInline())
	names.Add("inline");
else if (static_cast<AdeDestructor*>(myModelElement)->GetTraceLevel())
{
    AdeModelElement* aElement = myModelElement->GetGrandParent();
    AdeClass* aClass = dynamic_cast<AdeClass*>(aElement);
	if (aClass && aClass->IsTraced())
        names.Add("tracable");
    delete aElement;
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
else
{
	if (myModelElement->IsUndocumented())
		names.Add("isundocumented");
	else if (myModelElement->ContainsUndocumented())
		names.Add("containundocumented");
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
