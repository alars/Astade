wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeOperation::CreateNewElement(parentPath);
UpdateSubtree(aID);