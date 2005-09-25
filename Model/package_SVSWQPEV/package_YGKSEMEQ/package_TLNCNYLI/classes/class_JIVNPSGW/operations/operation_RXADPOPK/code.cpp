while (theParentTreeItem.IsOk())
{
	theParentTree->UpdateItem(theParentTreeItem);
	theParentTreeItem = theParentTree->GetItemParent(theParentTreeItem);
}

delete this;