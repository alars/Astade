wxTreeItemId aID = myTree->GetSelection();
wxFileName destination = myTree->GetItem(aID)->GetFileName();

wxFileName source = myTree->GetItem(relationStart)->GetFileName();

wxFileName theNewRelation = AdeRelation::CreateNewElement(source,destination);

myTree->GetItemObject(relationStart)->Touch();

relationStart = wxTreeItemId();
AstadeClass::SetRelationSourceName(wxEmptyString);

myTree->ShowNode(theNewRelation);