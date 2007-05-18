wxTreeItemId aID = myTree->GetSelection();

AdeModelElement* aElement = myTree->GetItem(aID);
aElement->Rename();

aID = myTree->GetItemParent(aID);

UpdateSubtree(aID);