//~~ void OnRightMouseClick(wxTreeEvent& event) [AstadeFrame] ~~

++rightMouseClickCount;
wxMenu* aPopUp = new wxMenu(wxEmptyString);

int flags = 0;
wxTreeItemId anID = myTree->HitTest(myTree->ScreenToClient(wxGetMousePosition()), flags);

if (!anID.IsOk() || (flags & (wxTREE_HITTEST_ONITEMLABEL | wxTREE_HITTEST_ONITEMICON)) == 0)
{
	wxConfigBase* theConfig = wxConfigBase::Get();
	wxString activeGUID = theConfig->Read("TreeView/ActiveGUID");
	AdeModelElement* anElement = AdeModelElement::CreateNewElement(AdeGUIDCache::Instance()->GetCachedEntry(activeGUID));
	AdeComponent* aComponent = dynamic_cast<AdeComponent*>(anElement);
	if (aComponent)
	{
		aPopUp->Append(-1, "Active component classes:", AstadeComponent::CreateJumpMenu(*aComponent));
	}
	delete anElement;
}
else
{
	myTree->SelectItem(anID);
	AstadeTreeItemBase* aTreeItem = myTree->GetItemObject(anID);

	aTreeItem->AppendMenuItems(*aPopUp);
}

PopupMenu(aPopUp);    //From wxWindow::
delete aPopUp;
--rightMouseClickCount;
