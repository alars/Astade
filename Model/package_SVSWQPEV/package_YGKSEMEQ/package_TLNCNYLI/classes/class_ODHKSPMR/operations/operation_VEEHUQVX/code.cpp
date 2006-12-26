if(copySource.IsOk() && IsPasteAble()) // check wether copySource is ok
{
	wxTreeItemId aID = myTree->GetSelection();
	wxFileName destination = myTree->GetItem(aID)->GetFileName();

	AdeModelElement* aElement = myTree->GetItem(copySource);    //For polymorphism.

	wxFileName parentPath;
	parentPath.AssignDir(destination.GetPath());			   //directory where to make copy for whatever element from Astade tree.

	if(doCut)
	{
		aElement->Move(parentPath);                          //
		myTree->Delete(copySource);
		copySource.Unset();
	}
	else
	{
		aElement->CreateCopy(parentPath);                          //Applying polymorphism CreateCopy(...). An element should define this function.
	}

	UpdateSubtree(aID);
}