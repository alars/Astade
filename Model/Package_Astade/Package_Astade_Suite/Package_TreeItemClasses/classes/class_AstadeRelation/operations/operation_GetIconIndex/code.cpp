//~~ int GetIconIndex() [AstadeRelation] ~~

wxArrayString names;

wxFileConfig theConfig(wxEmptyString, wxEmptyString, wxEmptyString, myModelElement->GetFileName().GetFullPath());

wxString RelationType = theConfig.Read(wxS("Astade/RelationType"));

if (RelationType == wxS("ImplementationDependency"))
{
	names.Add(wxS("relation"));
	names.Add(CODE_CPlusPlus);
}
else if (RelationType == wxS("SpecificationDependency"))
{
	names.Add(wxS("relation"));
	names.Add(wxS("h"));
}
else if (RelationType == wxS("Friend"))
	names.Add(wxS("relation"));
else if (RelationType == wxS("Association"))
	names.Add(wxS("association"));
else if (RelationType == wxS("Aggregation"))
	names.Add(wxS("aggregation"));
else if (RelationType == wxS("Composition"))
	names.Add(wxS("composition"));
else if (RelationType == wxS("Generalization"))
	names.Add(wxS("generalisation"));
else
	assert(false);

if (static_cast<AdeRelation*>(myModelElement)->IsStatic())
	names.Add(wxS("static"));

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
else
{
	if (myModelElement->IsUndocumented())
		names.Add(wxS("isundocumented"));
	else if (myModelElement->ContainsUndocumented())
		names.Add(wxS("containundocumented"));
}

AdeRelationBase* aRelation = dynamic_cast<AdeRelationBase*>(myModelElement);

if (aRelation)
{
    AdeClass* partner = dynamic_cast<AdeClass*>(aRelation->GetPartner());
    if (partner)
    {
        if (partner->IsInActiveComponent())
            names.Add(wxS("belonging"));
        delete partner;
    }
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index >= 0);

return index;

