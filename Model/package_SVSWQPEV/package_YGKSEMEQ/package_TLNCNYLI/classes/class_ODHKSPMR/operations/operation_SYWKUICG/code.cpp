myTree->DecUpdateThreadCounter();

if (event.treeItemId.IsOk())
	myTree->SetItemImage(event.treeItemId, event.iconIndex);

myTree->DoUpdateItem();