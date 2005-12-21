wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

AdeComponent::CreateNewElement(parentPath);
UpdateSubtree(aID);