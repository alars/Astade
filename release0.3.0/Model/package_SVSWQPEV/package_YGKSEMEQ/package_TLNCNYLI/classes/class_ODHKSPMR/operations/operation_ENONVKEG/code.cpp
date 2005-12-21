wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdePackage::CreateNewElement(parentPath);
UpdateSubtree(aID);