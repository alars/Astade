		wxTreeItemId aID = myTree->GetSelection();
AdeRelationBase* aRelation = dynamic_cast<AdeRelationBase*>(myTree->GetItem(aID));

myTree->ShowNode(aRelation->GetPartnerFile());
