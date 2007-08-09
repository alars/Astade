relationStart = wxTreeItemId();
AstadeClass::SetRelationSourceName(wxEmptyString);
copySource = wxTreeItemId();
wxTreeItemId aID = event.GetItem();

// cancel the update process of all children to be delete
wxTreeItemIdValue aCookie;
wxTreeItemId aChildID = myTree->GetFirstChild(aID, aCookie);
while(aChildID.IsOk()) {
	myTree->CancelUpdate(aChildID);
	aChildID = myTree->GetNextChild(aID, aCookie);
}

myTree->DeleteChildren(aID);