wxTreeItemId aID = myTree->GetSelection();

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read("TreeView/ActiveComponent");

AdeModelElement* activeComponent = AdeModelElement::CreateNewElement(activeComponentName);

AdeComponent* theActiveComponent = dynamic_cast<AdeComponent*>(activeComponent);

if (theActiveComponent == 0)
	return;

theActiveComponent->RemoveFromComponent(*(myTree->GetItem(aID)));

myTree->UpdateItem(aID);