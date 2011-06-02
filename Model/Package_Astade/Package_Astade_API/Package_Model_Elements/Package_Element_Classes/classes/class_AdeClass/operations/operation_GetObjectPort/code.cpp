//~~ wxString GetObjectPort(const wxString& objectName, const wxString& portName) [AdeClass] ~~

wxString ret;
AdeRelations* theRelations = GetRelations();

if (theRelations)
{
	for (AdeElementIterator it = theRelations->begin(); it != theRelations->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		wxASSERT(anElement);

		AdeRelation* aRelation = dynamic_cast<AdeRelation*>(anElement);
        
        if (aRelation && aRelation->GetName() == objectName && (aRelation->GetType() & ITEM_RELATION_MASK) == ITEM_IS_COMPOSITION)
        {
            wxFileName partnerFileName = aRelation->GetPartnerFile();
            if (partnerFileName.FileExists())
            {
                partnerFileName.RemoveLastDir();
                partnerFileName.SetFullName("ModelNode.ini");
                AdeClass* aClass = dynamic_cast<AdeClass*>(AdeModelElement::CreateNewElement(partnerFileName));
                if (aClass)
                {
                    wxString aPort = aClass->GetPort(portName);
                    if (!aPort.empty())
                        ret = objectName + "." + aPort;
                    delete aClass;
                }
            }
        }       
        
		delete anElement;

	}
    delete theRelations;
}

return ret;
