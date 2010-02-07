if((menuId<ID_OVERLOADMIN) || (menuId>ID_OVERLOADMAX))
{
	wxASSERT_MSG(false, "AstadeOperations::OverloadOperation(): id out of range!");
	return wxFileName();
}

// search cache for index
std::map<int, wxString>::iterator it = overloadIDs.find(menuId);
if(it==overloadIDs.end())
{
	wxASSERT_MSG(false, "AstadeOperations::OverloadOperation(): id not found!");
	return wxFileName();
}

// get AdeOperation from cached filename
AdeOperationBase* aOperation = dynamic_cast<AdeOperationBase*>(AdeModelElement::CreateNewElement(it->second));

if (aOperation == NULL)
	return wxFileName();

wxFileName newFile = aOperation->CreateCopy(myModelElement->GetFileName());
AdeOperationBase* newOperation = dynamic_cast<AdeOperationBase*>(AdeModelElement::CreateNewElement(newFile));

if (newOperation == NULL)
	return wxFileName();

newOperation->SetIsAbstract(false);

delete(aOperation);
delete(newOperation);

return newFile;
