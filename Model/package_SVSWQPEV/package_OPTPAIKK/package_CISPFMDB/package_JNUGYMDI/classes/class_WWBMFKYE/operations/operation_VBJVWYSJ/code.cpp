std::set<wxString> retVal;

if(GetHasRelations())
{
	wxFileName aFileName = myFileName;
	aFileName.AppendDir("relations");

	AdeRelations* theRelations = dynamic_cast<AdeRelations*>(AdeModelElement::CreateNewElement(aFileName));
	wxASSERT(theRelations);
	if(theRelations)
	{
		AdeElementIterator it;
		for(it=theRelations->begin(); it!=theRelations->end(); ++it)
		{
			AdeModelElement* aElement = it.CreateNewElement();
			wxASSERT(aElement);

			if(	((aElement->GetType() & ITEM_TYPE_MASK)==ITEM_IS_RELATION) &&
				((aElement->GetType() & ITEM_RELATION_MASK) == ITEM_IS_GENERALIZATION) )
			{
				wxFileName PartnerFile = dynamic_cast<AdeRelationBase*>(aElement)->GetPartnerFile();
				PartnerFile.RemoveDir(PartnerFile.GetDirCount()-1);
				PartnerFile.SetFullName("ModelNode.ini");
				printf("BaseClass found: %s\n", aElement->GetLabel().c_str());
				retVal.insert(PartnerFile.GetFullPath());
			}

			delete(aElement);
		}
	}
}

return retVal;
