//~~ std::map<wxString, wxString> GetVirtualOperations() [AdeClass] ~~

std::map<wxString, wxString> retVal;
AdeOperations* theOperations = GetOperations();
if (theOperations)
{
	for (AdeElementIterator it = theOperations->begin(); it != theOperations->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		wxASSERT(anElement);

		AdeOperationBase* aOperation = dynamic_cast<AdeOperationBase*>(anElement);
		wxASSERT_MSG(aOperation, "the operations folder should only contain operations");
		if (aOperation && aOperation->IsVirtual())
			retVal[aOperation->GetSignature()] = aOperation->GetFileName().GetFullPath();

		delete anElement;
	}
}

delete theOperations;

return retVal;
