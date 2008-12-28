wxArrayString names;

wxFileConfig thePartnerConfig(wxEmptyString,wxEmptyString,wxEmptyString,static_cast<AdeInRelation*>(myModelElement)->GetPartnerFile().GetFullPath());

wxString RelationType = thePartnerConfig.Read("Astade/RelationType");

if (RelationType=="ImplementationDependency")
{
	names.Add("inrelation");
	names.Add("cpp");
}
else if (RelationType=="SpecificationDependency")
{
	names.Add("inrelation");
	names.Add("h");
}
else if (RelationType=="Friend")
	names.Add("inrelation");
else if (RelationType=="Association")
	names.Add("inassociation");
else if (RelationType=="Aggregation")
	names.Add("inaggregation");
else if (RelationType=="Composition")
	names.Add("incomposition");
else if (RelationType=="Generalization")
	names.Add("ingeneralisation");
else
	assert(false);

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;
