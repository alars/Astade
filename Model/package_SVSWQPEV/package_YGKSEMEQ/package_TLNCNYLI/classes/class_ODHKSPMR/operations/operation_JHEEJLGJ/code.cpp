wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

wxFileName theNewType = AdeType::CreateNewElement(parentPath);
UpdateSubtree(aID);
myTree->ShowNode(theNewType);