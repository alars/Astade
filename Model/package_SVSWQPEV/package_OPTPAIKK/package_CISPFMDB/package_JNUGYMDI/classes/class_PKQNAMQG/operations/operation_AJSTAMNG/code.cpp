/* vi: set tabstop=4: */

wxFileConfig ownConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());
wxString RelationType = ownConfig.Read("Astade/RelationType");

if (RelationType == "ImplementationDependency")
	return AdeFileElement::GetType() + ITEM_IS_IMPL_DEPENDENCY;

if (RelationType == "SpecificationDependency")
	return AdeFileElement::GetType() + ITEM_IS_SPEC_DEPENDENCY;

if (RelationType == "Association")
	return AdeFileElement::GetType() + ITEM_IS_ASSOCIATION;

if (RelationType == "Aggregation")
	return AdeFileElement::GetType() + ITEM_IS_AGGREGATION;

if (RelationType == "Composition")
	return AdeFileElement::GetType() + ITEM_IS_COMPOSITION;

if (RelationType == "Generalization")
	return AdeFileElement::GetType() + ITEM_IS_GENERALIZATION;

if (RelationType == "Friend")
	return AdeFileElement::GetType() + ITEM_IS_FRIEND;

return AdeFileElement::GetType();
