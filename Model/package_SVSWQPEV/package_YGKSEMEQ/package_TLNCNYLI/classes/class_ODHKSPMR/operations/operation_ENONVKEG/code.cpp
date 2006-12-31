wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

wxFileName theNewPackage = AdePackage::CreateNewElement(parentPath);
UpdateSubtree(aID);
myTree->ShowNode(theNewPackage);