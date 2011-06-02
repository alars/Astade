//~~ void ReEngineer(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();

if (!anID.IsOk())
	return;

wxFileName theNewElement = myTree->GetItemObject(anID)->ReEngineer();

if (theNewElement.IsOk())
	myTree->AppendItem(anID, theNewElement);
