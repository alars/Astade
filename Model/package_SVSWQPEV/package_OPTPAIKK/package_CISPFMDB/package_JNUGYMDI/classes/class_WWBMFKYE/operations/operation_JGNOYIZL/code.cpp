std::map<wxString, wxString> retVal;

AdeOperations* theOperations = GetOperations();
if(theOperations)
{
	for(AdeElementIterator it = theOperations->begin(); it != theOperations->end(); ++it)
	{
		AdeModelElement* aElement = it.CreateNewElement();
		wxASSERT(aElement);

		AdeOperationBase* aOperation = dynamic_cast<AdeOperationBase*>(aElement);
		wxASSERT_MSG(aOperation, "the operations folder should only contain operations");
		if(aOperation && aOperation->IsVirtual())
			retVal[aOperation->GetSignature()] = aOperation->GetFileName().GetFullPath();

		delete(aElement);
	}
}

delete(theOperations);

return retVal;