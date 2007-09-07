if (indexBase == -1) // not yet initialized
	InitializeIcons();

wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myModelElement->GetFileName().GetFullPath());

wxString RelationType = theConfig.Read("Astade/RelationType");

int ret = indexBase;

if (RelationType=="SpecificationDependency")
	ret += 1;

if (RelationType=="Friend")
	ret += 2;

if (RelationType=="Association")
{
	ret += 3;
	if (static_cast<AdeRelation*>(myModelElement)->IsStatic())
		ret += 7;
}

if (RelationType=="Aggregation")
{
	ret += 4;
	if (static_cast<AdeRelation*>(myModelElement)->IsStatic())
		ret += 7;
}

if (RelationType=="Composition")
{
	ret += 5;
	if (static_cast<AdeRelation*>(myModelElement)->IsStatic())
		ret += 7;
}

if (RelationType=="Generalization")
	ret += 6;

return ret;