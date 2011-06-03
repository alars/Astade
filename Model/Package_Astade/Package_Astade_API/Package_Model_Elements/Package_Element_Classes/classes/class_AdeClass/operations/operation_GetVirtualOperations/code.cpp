//~~ std::map<wxString, wxString> GetVirtualOperations() [AdeClass] ~~

std::map<wxString, wxString> retVal;
AdeOperations* theOperations = GetOperations();
if (theOperations)
{
	for (AdeElementIterator it = theOperations->begin(); it != theOperations->end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		wxASSERT(anElement);

		AdeOperationBase* anOperation = dynamic_cast<AdeOperationBase*>(anElement);
		wxASSERT_MSG(anOperation, "the operations folder should only contain operations");
		if (anOperation && anOperation->IsVirtual())
			retVal[anOperation->GetSignature()] = anOperation->GetFileName().GetFullPath();

		delete anElement;
	}
}

delete theOperations;

return retVal;
