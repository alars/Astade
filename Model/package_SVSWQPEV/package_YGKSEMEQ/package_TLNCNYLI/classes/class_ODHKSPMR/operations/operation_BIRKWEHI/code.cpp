wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

wxFileName theClass = AdeClass::CreateNewElement(parentPath);

if (event.GetId()==ID_ADDLIBCLASS)
{
	AdeClass(theClass).SetIsLibClass();
}

UpdateSubtree(aID);