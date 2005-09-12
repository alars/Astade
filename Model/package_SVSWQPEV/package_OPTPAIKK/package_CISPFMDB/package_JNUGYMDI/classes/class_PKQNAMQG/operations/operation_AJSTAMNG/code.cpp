wxFileConfig ownConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());
wxString RelationType = ownConfig.Read("Astade/RelationType");

if (RelationType=="ImplementationDependency")
	return AdeFileElement::GetType() + 5;

if (RelationType=="SpecificationDependency")
	return AdeFileElement::GetType() + 4;

if (RelationType=="Association")
	return AdeFileElement::GetType() + 3;

if (RelationType=="Agregation")
	return AdeFileElement::GetType() + 2;

if (RelationType=="Composition")
	return AdeFileElement::GetType() + 1;

if (RelationType=="Generalization")
	return AdeFileElement::GetType() + 0;

return AdeFileElement::GetType() + 0;
