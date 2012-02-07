//~~ int GetIconIndex() [AstadeOperation] ~~

wxArrayString names;

names.Add(wxS("operation"));

wxString visibility = static_cast<AdeOperation*>(myModelElement)->GetVisibility();

if (visibility == wxS("private") || visibility == wxS("public") || visibility == wxS("protected"))
	names.Add(visibility);

if (static_cast<AdeOperation*>(myModelElement)->IsConst())
	names.Add(wxS("const"));

if (static_cast<AdeOperation*>(myModelElement)->IsStatic())
	names.Add(wxS("static"));

AdeClass* parentClass = dynamic_cast<AdeClass*>(myModelElement->GetGrandParent());

bool isOverridden = false;

if (parentClass)
{
    std::map<wxString, wxString> ops = parentClass->GetOverloadableOperations();
    if (ops.find(static_cast<AdeOperation*>(myModelElement)->GetSignature()) != ops.end())
    {
        isOverridden = true;
        names.Add(wxS("overrides"));
        static_cast<AdeOperation*>(myModelElement)->SetVirtual(true); 
    }
    delete parentClass;
}

if (!isOverridden && static_cast<AdeOperation*>(myModelElement)->IsAbstract())
	names.Add(wxS("abstract"));
else if (!isOverridden && static_cast<AdeOperation*>(myModelElement)->IsVirtual())
	names.Add(wxS("virtual"));

if (static_cast<AdeOperation*>(myModelElement)->IsInline())
{
	names.Add(wxS("inline"));
}
else if (static_cast<AdeOperation*>(myModelElement)->GetTraceLevel())
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

if (!myModelElement->GetConstraint().empty())
	names.Add(wxS("constraint"));

if(static_cast<AdeOperation*>(myModelElement)->IsDeprecated())
	names.Add(wxS("deprecated"));

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
