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
	if(aElement->GetFileName() != parentPath)
	{
		if(dest->CanContain(*aElement))
		{
			aElement->CreateCopy(parentPath); // copy the element here
			UpdateSubtree(aID);
			retVal = true;
		}
		// if the source is a class and the destination is a relations-folder => create a relation
		else if(   ((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_CLASS)
				&& ((dest->GetType()     & ITEM_TYPE_MASK) == ITEM_IS_RELATIONS) )
		{
			wxTreeItemId startId = myTree->GetItemParent(aID);
			wxFileName theNewRelation = AdeRelation::CreateNewElement(myTree->GetItem(startId)->GetFileName(), aElement->GetFileName());
			UpdateSubtree(aID);
			myTree->ShowNode(theNewRelation);
		}
		else
		{
			wxLogMessage("This type of element cannot be dropped here!");
		}
	}
	else
	{
		wxLogMessage("The element cannot be copied to itself!");
	}
	delete(aElement);
}
else
{
	wxLogMessage("Only one file can be dropped to Astade at once!");
}

return retVal;