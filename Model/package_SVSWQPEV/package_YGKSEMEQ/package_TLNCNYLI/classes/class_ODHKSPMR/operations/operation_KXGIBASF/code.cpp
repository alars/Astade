wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

wxFileName theNewState = AdeState::CreateNewElement(parentPath);
UpdateSubtree(aID);
myTree->ShowNode(theNewState);