wxTreeItemId aId = AstadeTreeItemBase::GetId4Update();

if (aId.IsOk())
{
	myTree->GetItemObject(aId)->Update();
	event.RequestMore();
	SetStatusText("updating...",0);
}
else
{
	SetStatusText("done!",0);
}
