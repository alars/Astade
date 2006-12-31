wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

wxFileName theNewTransition = AdeTransition::CreateNewElement(parentPath);
UpdateSubtree(aID);
myTree->ShowNode(theNewTransition);