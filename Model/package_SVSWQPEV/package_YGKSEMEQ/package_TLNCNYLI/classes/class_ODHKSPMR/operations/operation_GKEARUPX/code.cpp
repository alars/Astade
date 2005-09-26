wxTreeItemId aID = event.GetItem();
AdeDirectoryElement* aDir = static_cast<AdeDirectoryElement*>(myTree->GetItem(aID));

AdeElementIterator iter;
for (iter = aDir->begin(); iter != aDir->end(); ++iter)
{
	wxTreeItemId newItem = myTree->AppendItem(aID,"loading ...", 48);
	myTree->SetItem(newItem,iter.CreateNewElement());
	myTree->UpdateItem(newItem);
}

myTree->SortChildren(aID);