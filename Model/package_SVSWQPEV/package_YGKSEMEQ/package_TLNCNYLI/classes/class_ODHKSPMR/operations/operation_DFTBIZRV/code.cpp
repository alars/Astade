wxTreeItemId aID = myTree->GetSelection();
wxFileName destination = myTree->GetItem(aID)->GetFileName();

wxFileName source = myTree->GetItem(relationStart)->GetFileName();
wxFileName relations(source);

wxFileName theNewRelation = AdeRelation::CreateNewElement(source,destination);

relations.SetFullName("ModelNode.ini");
relations.AppendDir("relations");

myTree->SetItemHasChildren(relationStart);
wxTreeItemId relationsID = myTree->ShowNode(relations);

if (myTree->GetItem(relationsID)->GetFileName() != relations)
{

	AdeModelElement* aElement = AdeModelElement::CreateNewElement(relations);
	wxTreeItemId newItem = myTree->AppendItem(relationStart,"loading ...", 48);
	myTree->EnsureVisible(newItem);
	myTree->SetItem(newItem,aElement);
	relationsID = myTree->ShowNode(relations);
}

myTree->AppendItem(relationsID, theNewRelation);

relationStart = wxTreeItemId();
AstadeClass::SetRelationSourceName(wxEmptyString);