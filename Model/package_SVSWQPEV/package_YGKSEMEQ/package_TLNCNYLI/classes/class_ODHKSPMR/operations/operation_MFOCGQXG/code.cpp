wxTreeItemId aID = myTree->GetSelection();
AdeModelElement* element = myTree->GetItem(aID);

AdeComponent* component = dynamic_cast<AdeComponent*>(element);

if (component)
{
	component->MakeActiveComponent();
	myTree->UpdateAll(myTree->GetRootItem());
}
