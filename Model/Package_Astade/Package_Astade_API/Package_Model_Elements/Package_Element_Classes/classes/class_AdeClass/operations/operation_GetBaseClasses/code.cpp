std::set<wxString> retVal;

if (HasRelations())
{
	wxFileName aFileName = myFileName;
	aFileName.AppendDir(wxS("relations"));

	AdeModelElement* relationsElement = AdeModelElement::CreateNewElement(aFileName);
	AdeRelations* theRelations = dynamic_cast<AdeRelations*>(relationsElement);

	if(theRelations)
	{
		for(AdeElementIterator it = theRelations->begin(); it != theRelations->end(); ++it)
		{
			AdeModelElement* aElement = it.CreateNewElement();
			wxASSERT(aElement);

			int elementType = aElement->GetType();

			if(	((elementType & ITEM_TYPE_MASK) == ITEM_IS_RELATION) &&
				((elementType & ITEM_RELATION_MASK) == ITEM_IS_GENERALIZATION) )
			{
				wxFileName PartnerFile = dynamic_cast<AdeRelationBase*>(aElement)->GetPartnerFile();
				PartnerFile.RemoveLastDir();
				PartnerFile.SetFullName(wxS("ModelNode.ini"));
				retVal.insert(PartnerFile.GetFullPath());

				// recursion
				AdeModelElement* classElement = AdeModelElement::CreateNewElement(PartnerFile);
				AdeClass* aParentClass = dynamic_cast<AdeClass*>(classElement);

				wxASSERT_MSG(aParentClass != 0, wxS("This should be a class, because someone inherits from here!"));
				if (aParentClass)
				{
					std::set<wxString> subVal = aParentClass->GetBaseClasses();
					if (!subVal.empty())
						retVal.insert(subVal.begin(), subVal.end());
				}
				delete classElement;
			}

			delete aElement;
		}
	}
	delete relationsElement;
}

return retVal;
