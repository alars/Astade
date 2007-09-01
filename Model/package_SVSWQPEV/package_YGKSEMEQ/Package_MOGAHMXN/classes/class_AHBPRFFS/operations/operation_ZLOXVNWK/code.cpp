if (indexBase == -1) // not yet initialized
	InitializeIcons();

wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myModelElement->GetFileName().GetFullPath());

wxString RelationType = theConfig.Read("Astade/RelationType");

if (RelationType=="ImplementationDependency")
	return indexBase;

if (RelationType=="SpecificationDependency")
	return indexBase + 1;

if (RelationType=="Friend")
	return indexBase + 2;

if (RelationType=="Association")
	return indexBase + 3;

if (RelationType=="Aggregation")
	return indexBase + 4;

if (RelationType=="Composition")
	return indexBase + 5;

if (RelationType=="Generalization")
	return indexBase + 6;

return 1;
