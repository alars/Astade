relationStart = wxTreeItemId();
AstadeClass::SetRelationSourceName(wxEmptyString);
wxTreeItemId aID = event.GetItem();

myTree->DeleteChildren(aID);
