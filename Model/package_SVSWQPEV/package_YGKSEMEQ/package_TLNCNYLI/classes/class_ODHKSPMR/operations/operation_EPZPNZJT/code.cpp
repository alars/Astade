wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeEvent::CreateNewElement(parentPath);
UpdateSubtree(aID);