//~~ void OverloadOperation(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();

if (!anID.IsOk())
	return;

AstadeOperations* anOperations = dynamic_cast<AstadeOperations*>(myTree->GetItemObject(anID));

if (anOperations)
{
	wxFileName theNewElement = anOperations->OverloadOperation(event.GetId());
	wxASSERT_MSG(theNewElement.FileExists(), "AstadeFrame::OverloadOperation(): Overload returns a non existing file!");
	myTree->AppendItem(anID, theNewElement);
}
