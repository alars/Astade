/* vi: set tabstop=4: */

wxString RelationType(myConfig->Read(wxS("Astade/RelationType")));

if (RelationType == wxS("ImplementationDependency"))
	return AdeFileElement::GetType() + ITEM_IS_IMPL_DEPENDENCY;

if (RelationType == wxS("SpecificationDependency"))
	return AdeFileElement::GetType() + ITEM_IS_SPEC_DEPENDENCY;

if (RelationType == wxS("Association"))
	return AdeFileElement::GetType() + ITEM_IS_ASSOCIATION;

if (RelationType == wxS("Aggregation"))
	return AdeFileElement::GetType() + ITEM_IS_AGGREGATION;

if (RelationType == wxS("Composition"))
	return AdeFileElement::GetType() + ITEM_IS_COMPOSITION;

if (RelationType == wxS("Generalization"))
	return AdeFileElement::GetType() + ITEM_IS_GENERALIZATION;

if (RelationType == wxS("Friend"))
	return AdeFileElement::GetType() + ITEM_IS_FRIEND;

return AdeFileElement::GetType();
