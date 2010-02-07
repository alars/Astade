wxArrayString names;

wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myModelElement->GetFileName().GetFullPath());

wxString RelationType = theConfig.Read("Astade/RelationType");

if (RelationType=="ImplementationDependency")
{
	names.Add("relation");
	names.Add("cpp");
}
else if (RelationType=="SpecificationDependency")
{
	names.Add("relation");
	names.Add("h");
}
else if (RelationType=="Friend")
	names.Add("relation");
else if (RelationType=="Association")
	names.Add("association");
else if (RelationType=="Aggregation")
	names.Add("aggregation");
else if (RelationType=="Composition")
	names.Add("composition");
else if (RelationType=="Generalization")
	names.Add("generalisation");
else
	assert(false);

if (static_cast<AdeRelation*>(myModelElement)->IsStatic())
	names.Add("static");

if (search->isSet(AdeSearch::SearchIsActive))
{
	switch (myModelElement->Search(*search))
	{
		case AdeSearch::contain: names.Add("hasfound");break;
		case AdeSearch::found: names.Add("found");break;
		default: break;
	}
}
else
{
	if(myModelElement->IsUndocumented())
		names.Add("isundocumented");
	else if(myModelElement->ContainsUndocumented())
		names.Add("containundocumented");
}

int index = AstadeIcons::Instance()->GetIconIndex(names);

assert(index>=0);

return index;

