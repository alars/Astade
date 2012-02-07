//~~ int GetIconIndex() [AstadeDestructor] ~~

wxArrayString names;

names.Add(wxS("operation"));
names.Add(wxS("destructor"));

wxString visibility = static_cast<AdeDestructor*>(myModelElement)->GetVisibility();

if (visibility == wxS("private") || visibility == wxS("public") || visibility == wxS("protected"))
	names.Add(visibility);

AdeClass* parentClass = dynamic_cast<AdeClass*>(myModelElement->GetGrandParent());

bool isOverridden = false;

if (parentClass)
{
    std::map<wxString, wxString> ops = parentClass->GetOverloadableOperations();
    for (std::map<wxString, wxString>::iterator it = ops.begin(); it != ops.end(); it++)
    {
        if ((*it).first.Find('~') == 0)
        {
            isOverridden = true;
            names.Add(wxS("overrides"));
            static_cast<AdeDestructor*>(myModelElement)->SetVirtual(true); 
            break;
        }
    }
    delete parentClass;
}

if (!isOverridden && static_cast<AdeDestructor*>(myModelElement)->IsVirtual())
	names.Add(wxS("virtual"));

if (static_cast<AdeDestructor*>(myModelElement)->IsInline())
{
	names.Add(wxS("inline"));
}
else if (static_cast<AdeDestructor*>(myModelElement)->GetTraceLevel())
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
