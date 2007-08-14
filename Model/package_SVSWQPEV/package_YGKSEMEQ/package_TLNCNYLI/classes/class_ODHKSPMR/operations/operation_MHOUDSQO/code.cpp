/* vi: set tabstop=4: */

wxMenu* aPopUp = new wxMenu(wxEmptyString);

int flags = 0;
wxTreeItemId aID = myTree->HitTest(myTree->ScreenToClient(wxGetMousePosition()),flags);

if (!aID.IsOk() || (flags & (wxTREE_HITTEST_ONITEMLABEL | wxTREE_HITTEST_ONITEMICON)) == 0)
{
	wxConfigBase* theConfig = wxConfigBase::Get();
	wxString activeGUID = theConfig->Read("TreeView/ActiveGUID");
	AdeModelElement* aElement = AdeModelElement::CreateNewElement(AdeGUIDCache::Instance()->GetCachedEntry(activeGUID));
	AdeComponent* aComponent = dynamic_cast<AdeComponent*>(aElement);
	if (aComponent)
	{
		aPopUp->Append(-1,"Active component classes:",CreateJumpMenu(*aComponent));
	}
	delete aElement;
}
else
{
	myTree->SelectItem(aID);
	AstadeTreeItemBase* aTreeItem = myTree->GetItemObject(aID);

	if (copySource.IsOk())
		myTree->GetItemObject(copySource)->SetToGlobalCopySource();

	aTreeItem->AppendMenuItems(*aPopUp);
}

PopupMenu(aPopUp);    //From wxWindow::
delete aPopUp;
