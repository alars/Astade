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
            names.Add("overrides");
            static_cast<AdeDestructor*>(myModelElement)->SetVirtual(true); 
            break;
        }
    }
    delete parentClass;
}

if (!isOverridden && static_cast<AdeDestructor*>(myModelElement)->IsVirtual())
	names.Add("virtual");

if (static_cast<AdeDestructor*>(myModelElement)->IsInline())
{
	names.Add("inline");
}
else if (static_cast<AdeDestructor*>(myModelElement)->GetTraceLevel())
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
