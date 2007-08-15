wxTreeItemId aId = AstadeTreeItemBase::GetId4Update();

if (aId.IsOk())
{
	myTree->DoUpdateItem(aId);
	event.RequestMore();
}