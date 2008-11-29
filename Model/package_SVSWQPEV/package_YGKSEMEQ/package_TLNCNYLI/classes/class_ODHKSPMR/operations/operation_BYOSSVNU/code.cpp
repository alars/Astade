wxTreeItemId aID = myTree->GetSelection();

if (!aID.IsOk())
	return;

wxFileName theNewElement = myTree->GetItemObject(aID)->ReEngineer();

if (theNewElement.IsOk())
	myTree->AppendItem(aID, theNewElement);
