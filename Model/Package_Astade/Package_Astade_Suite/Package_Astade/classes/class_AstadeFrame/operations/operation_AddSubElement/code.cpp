//~~ void AddSubElement(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();
if (!anID.IsOk())
	return;

wxFileName theNewElement = myTree->GetItemObject(anID)->AddSubElement(event.GetId());
myTree->AppendItem(anID, theNewElement);
