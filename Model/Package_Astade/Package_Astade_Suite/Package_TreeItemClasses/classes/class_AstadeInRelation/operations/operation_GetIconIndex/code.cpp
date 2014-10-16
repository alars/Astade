//~~ int GetIconIndex() [AstadeInRelation] ~~

wxArrayString names;

wxFileConfig thePartnerConfig(wxEmptyString, wxEmptyString, wxEmptyString, static_cast<AdeInRelation*>(myModelElement)->GetPartnerFile().GetFullPath());

wxString RelationType = thePartnerConfig.Read(wxS("Astade/RelationType"));

if (RelationType == wxS("ImplementationDependency"))
{
	names.Add(wxS("inrelation"));
	names.Add(CODE_CPlusPlus);
}
else if (RelationType == wxS("SpecificationDependency"))
{
	names.Add(wxS("inrelation"));
	names.Add(wxS("h"));
}
else if (RelationType == wxS("Friend"))
	names.Add(wxS("inrelation"));
else if (RelationType == wxS("Association"))
	names.Add(wxS("inassociation"));
else if (RelationType == wxS("Aggregation"))
	names.Add(wxS("inaggregation"));
else if (RelationType == wxS("Composition"))
	names.Add(wxS("incomposition"));
else if (RelationType == wxS("Generalization"))
	names.Add(wxS("ingeneralisation"));
else
	assert(false);

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
