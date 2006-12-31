wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

wxFileName theNewAttribute = AdeAttribute::CreateNewElement(parentPath);
UpdateSubtree(aID);
myTree->ShowNode(theNewAttribute);