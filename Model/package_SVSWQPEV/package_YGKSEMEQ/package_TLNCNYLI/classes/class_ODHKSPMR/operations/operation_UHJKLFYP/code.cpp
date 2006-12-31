wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

wxFileName theNewOperation = AdeOperation::CreateNewElement(parentPath);
UpdateSubtree(aID);
myTree->ShowNode(theNewOperation);