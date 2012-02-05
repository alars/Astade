//~~ AdeModelElement* GetPartner() [AdeRelationBase] ~~

if (PartnerExists())
{
	wxFileName relation(GetPartnerFile());
	relation.RemoveLastDir();
	relation.SetFullName(wxS("ModelNode.ini"));
	return AdeModelElement::CreateNewElement(relation);
}
else
	return NULL;
