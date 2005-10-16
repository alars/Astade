wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeType::CreateNewElement(parentPath);
UpdateSubtree(aID);