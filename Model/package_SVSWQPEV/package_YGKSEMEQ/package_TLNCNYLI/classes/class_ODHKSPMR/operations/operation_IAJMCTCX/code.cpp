wxTreeItemId aID = myTree->GetSelection();

if (!aID.IsOk())
	return;

wxFileName theNewElement = myTree->GetItemObject(aID)->AddSubElement(event.GetId());
UpdateSubtree(aID);
myTree->ShowNode(theNewElement);