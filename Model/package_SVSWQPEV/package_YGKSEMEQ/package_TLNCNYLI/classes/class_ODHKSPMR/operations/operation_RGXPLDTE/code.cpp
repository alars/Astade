for (int i=0;!myTree->theUpdateItemList.empty() && i < 5;++i)
{
	wxTreeItemId aID = myTree->theUpdateItemList.front();
	myTree->theUpdateItemList.pop_front();
	myTree->DoUpdateItem(aID);
}