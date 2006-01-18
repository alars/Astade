wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeSequences::CreateNewElement(parentPath);
UpdateSubtree(aID);