//~~ void JumpToPartner(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();
AdeRelationBase* aRelation = dynamic_cast<AdeRelationBase*>(myTree->GetItem(anID));

myTree->ShowNode(aRelation->GetPartnerFile());
