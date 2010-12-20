//~~ void AddSubElement(wxCommandEvent& event) [AstadeFrame] ~~
		wxTreeItemId aID = myTree->GetSelection();

if (!aID.IsOk())
	return;

wxFileName theNewElement = myTree->GetItemObject(aID)->AddSubElement(event.GetId());
myTree->AppendItem(aID, theNewElement);
