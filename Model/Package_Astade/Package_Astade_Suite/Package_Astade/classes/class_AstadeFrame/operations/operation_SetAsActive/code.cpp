//~~ void SetAsActive(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();
AdeModelElement* element = myTree->GetItem(anID);

AdeComponent* component = dynamic_cast<AdeComponent*>(element);

if (component)
{
	component->MakeActiveComponent();
	myTree->UpdateAll(myTree->GetRootItem());
	UpdateToolbar();
}
