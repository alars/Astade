#define __OLDPASTE__ 1 // paste from clipboard does not work together with cut/move

#ifndef __OLDPASTE__

if(wxTheClipboard->Open())
{
	wxFileDataObject copyData;
	wxTheClipboard->GetData(copyData);
	wxArrayString filenames = copyData.GetFilenames(); // fetch copied filed from clipboard

	// accept only one file per paste (for testing)
	if(filenames.GetCount()==1)
	{

		wxTreeItemId aID = myTree->GetSelection();
		wxFileName destination = myTree->GetItem(aID)->GetFileName();
		wxFileName parentPath;
		parentPath.AssignDir(destination.GetPath());			   //directory where to make copy for whatever element from Astade tree.

		wxFileName aFile(filenames[0]); // take first filename
		AdeModelElement* aElement = AdeModelElement::CreateNewElement(aFile);

		// do this type of element fit here?
		if(dest->CanContain(*aElement))
		{		
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
		}
		else
		{
			wxLogMessage("This type of element cannot be pasted here!");
		}

	
		UpdateSubtree(aID);

	}
	
	wxTheClipboard->Close();
}
else
{
	wxLogMessage("Cannot open the Clipboard!");
}

#else

/* do not use the old paste method */
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
/*************************************/

#endif