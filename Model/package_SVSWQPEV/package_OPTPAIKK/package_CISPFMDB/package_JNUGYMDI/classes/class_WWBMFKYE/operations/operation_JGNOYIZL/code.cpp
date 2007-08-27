std::map<wxString, wxString> retVal;

// find all suboperations
std::map<wxString, wxString> subOps = GetOverloadableOperations();
retVal.insert(subOps.begin(), subOps.end());

// if we have operations, search for own virtual ones
AdeOperations* theOperations = GetOperations();
if(theOperations)
{
	AdeElementIterator it;
	for(it=theOperations->begin(); it!=theOperations->end(); ++it)
	{
		AdeModelElement* aElement = it.CreateNewElement();
		wxASSERT(aElement);

		AdeOperationBase* aOperation = dynamic_cast<AdeOperationBase*>(aElement);
		wxASSERT(aOperation); // the operations folder should only contain operations
		if(aOperation && aOperation->IsVirtual())
		{
			printf("Found virtual operation %s\n", aOperation->GetLabel().c_str());
			retVal[aOperation->GetSignature()] = aOperation->GetFileName().GetFullPath();
		}

		delete(aElement);
	}
}

delete(theOperations);

return retVal;