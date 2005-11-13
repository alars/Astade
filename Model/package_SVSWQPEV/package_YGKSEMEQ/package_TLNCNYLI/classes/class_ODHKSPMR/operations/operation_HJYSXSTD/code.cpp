wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeStatechart::CreateNewElement(parentPath);
UpdateSubtree(aID);