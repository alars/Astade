//~~ void RemoveFromComponent(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read("TreeView/ActiveComponent");

AdeModelElement* activeComponent = AdeModelElement::CreateNewElement(activeComponentName);

AdeComponent* theActiveComponent = dynamic_cast<AdeComponent*>(activeComponent);

if (theActiveComponent)
{
	theActiveComponent->RemoveFromComponent(*(myTree->GetItem(anID)));
	myTree->UpdateItem(anID);
}
delete activeComponent;
