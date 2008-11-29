wxTreeItemId aID = myTree->GetSelection();

if (!aID.IsOk())
	return;

AstadeOperations* aOperations = dynamic_cast<AstadeOperations*>(myTree->GetItemObject(aID));

if(aOperations)
{
	wxFileName theNewElement = aOperations->OverloadOperation(event.GetId());
	wxASSERT_MSG(theNewElement.FileExists(), "AstadeFrame::OverloadOperation(): Overload returns a non existing file!");
	myTree->AppendItem(aID, theNewElement);
}
