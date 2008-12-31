wxTreeItemId aId = AstadeTreeItemBase::GetId4Update();

if (aId.IsOk())
{
	if (myAstadeSearch.isSet(AdeSearch::SearchIsActive))
		SetStatusText("search...",0);
	else
		SetStatusText("update...",0);

	myTree->GetItemObject(aId)->Update();
	event.RequestMore();
}
else
{
	SetStatusText("done!",0);
}


if (itemToClose.IsOk())
{
	myTree->DeleteChildren(itemToClose);
	itemToClose = wxTreeItemId();
}