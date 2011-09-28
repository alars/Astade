//~~ int GetIconIndex() [AstadeOperation] ~~

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

AdeClass* parentClass = dynamic_cast<AdeClass*>(myModelElement->GetGrandParent());

bool isOverridden = false;

if (parentClass)
{
    std::map<wxString, wxString> ops = parentClass->GetOverloadableOperations();
    if (ops.find(static_cast<AdeOperation*>(myModelElement)->GetSignature()) != ops.end())
    {
        isOverridden = true;
        names.Add("overrides");
        static_cast<AdeOperation*>(myModelElement)->SetVirtual(true); 
    }
    delete parentClass;
}

if (!isOverridden && static_cast<AdeOperation*>(myModelElement)->IsAbstract())
	names.Add("abstract");
else if (!isOverridden && static_cast<AdeOperation*>(myModelElement)->IsVirtual())
	names.Add("virtual");

if (static_cast<AdeOperation*>(myModelElement)->IsInline())
{
	names.Add("inline");
}
else if (static_cast<AdeOperation*>(myModelElement)->GetTraceLevel())
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

if (!myModelElement->GetConstraint().empty())
		names.Add("constraint");

if(static_cast<AdeOperation*>(myModelElement)->IsDeprecated())
	names.Add("deprecated");

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;
