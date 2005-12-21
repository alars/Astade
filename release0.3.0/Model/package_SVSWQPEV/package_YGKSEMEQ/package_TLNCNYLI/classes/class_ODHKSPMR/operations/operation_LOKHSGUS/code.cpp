wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeComponents::CreateNewElement(parentPath);
UpdateSubtree(aID);