wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeEvents::CreateNewElement(parentPath);
UpdateSubtree(aID);