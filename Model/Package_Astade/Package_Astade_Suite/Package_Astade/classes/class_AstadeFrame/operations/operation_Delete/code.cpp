//~~ void Delete(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();

AdeModelElement* anElement = myTree->GetItem(anID);

if (anElement->HasChildren())
{
	wxMessageDialog aDialog(this,"Element is not empty, delete anyway?","Delete:",wxOK | wxCANCEL | wxICON_EXCLAMATION );
	if (aDialog.ShowModal() == wxID_CANCEL)
		return;
}

if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_CLASS ||
    (anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATECHART)
{
	// we're deleting a class - (try to) remove it from the active component first
	wxConfigBase* theConfig = wxConfigBase::Get();
	wxFileName activeComponentName = theConfig->Read("TreeView/ActiveComponent");
	AdeModelElement* activeComponent = AdeModelElement::CreateNewElement(activeComponentName);
	AdeComponent* theActiveComponent = dynamic_cast<AdeComponent*>(activeComponent);
	if (theActiveComponent)
		theActiveComponent->RemoveFromComponent(*anElement);
	delete activeComponent;
}

anElement->Delete();

wxTreeItemId parentID = myTree->GetItemParent(anID);

wxTreeItemId newID = myTree->GetPrevSibling(anID);

if (!newID.IsOk())
	newID = myTree->GetNextSibling(anID);

if (!newID.IsOk())
	newID = myTree->GetItemParent(anID);

myTree->SelectItem(newID);
myTree->Delete(anID);

myTree->GetItemObject(parentID)->Touch();
