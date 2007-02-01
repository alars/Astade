bool retVal = false;

wxTreeItemId aID = myTree->HitTest(point);
myTree->SelectItem(aID);
AdeModelElement* dest = myTree->GetItem(aID);
wxFileName parentPath = dest->GetFileName();

// accept only one file per drop (for testing)
if(filenames.GetCount()==1)
{
	wxFileName aFile(filenames[0]); // take first filename
	AdeModelElement* aElement = AdeModelElement::CreateNewElement(aFile);
	// did this type of element fit here?
	if(dest->CanContain(*aElement))
	{
		aElement->CreateCopy(parentPath); // copy the element here
		UpdateSubtree(aID);
		retVal = true;
	}
	delete(aElement);
}

return retVal;