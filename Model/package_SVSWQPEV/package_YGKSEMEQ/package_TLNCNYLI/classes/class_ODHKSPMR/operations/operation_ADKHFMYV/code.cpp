wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeState::CreateNewElement(parentPath);
UpdateSubtree(aID);