//~~ wxFileName OverloadOperation(int menuId) [AstadeOperations] ~~

if (menuId < ID_OVERLOADMIN || menuId > ID_OVERLOADMAX)
{
	wxASSERT_MSG(false, "AstadeOperations::OverloadOperation(): id out of range!");
	return wxFileName();
}

// search cache for index
std::map<int, wxString>::iterator it = overloadIDs.find(menuId);
if (it == overloadIDs.end())
{
	wxASSERT_MSG(false, "AstadeOperations::OverloadOperation(): id not found!");
	return wxFileName();
}

wxFileName newFile;
if (!it->second.StartsWith(wxS(":")))
{
	// get AdeOperation from cached filename
	AdeOperationBase* anOperation = dynamic_cast<AdeOperationBase*>(AdeModelElement::CreateNewElement(it->second));

	if (anOperation == NULL)
		return wxFileName();

	newFile = anOperation->CreateCopy(myModelElement->GetFileName());
	AdeOperationBase* newOperation = dynamic_cast<AdeOperationBase*>(AdeModelElement::CreateNewElement(newFile));

	if (newOperation)
		newOperation->SetAbstract(false);
	else
		newFile = wxFileName();
	delete newOperation;

	delete anOperation;
}
else
{
	// we're overloading a statechart action or guard - there's no element to copy from
	wxString returnType(it->second.Mid(1));
	int pos = returnType.Find(':');
	wxASSERT_MSG(pos != wxNOT_FOUND, "AstadeOperations: Bad signature!");
	wxString signature(returnType.Mid(pos + 1));
	returnType = returnType(0, pos);
	pos = signature.Find('(');
	wxASSERT_MSG(pos != wxNOT_FOUND, "AstadeOperations: Bad signature!");

	newFile = AdeOperation::CreateNewElement(myModelElement->GetFileName(),
				signature(0, pos), returnType, true);
	AdeOperation* newOperation = new AdeOperation(newFile);

    if (newOperation->GetReturntype() == wxS("bool"))
        newOperation->SetDescription(wxS("implements a guard from the undlerlaying state chart"));
    else
        newOperation->SetDescription(wxS("implements an action from the undlerlaying state chart"));

	int pos2 = signature.Find(')', true);
	if (pos2 != wxNOT_FOUND && pos2 > pos + 1)
	{
		wxFileName parms = AdeParameters::CreateNewElement(newFile);
		wxFileName param = AdeParameter::CreateNewElement(parms, wxS("event"),
							signature(pos + 1, pos2 - pos - 1));
        AdeParameter* tmpParameter = new AdeParameter(param);
        tmpParameter->SetDescription(wxS("the event which caused this call"));
        tmpParameter->SetIsInput(true);
        delete tmpParameter;
	}
	delete newOperation;
}

return newFile;
