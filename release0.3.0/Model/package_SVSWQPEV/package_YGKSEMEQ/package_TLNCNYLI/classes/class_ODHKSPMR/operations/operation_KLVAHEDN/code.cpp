wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeTransition::CreateNewElement(parentPath);
UpdateSubtree(aID);