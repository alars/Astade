bool retVal = false;

wxTreeItemId aID = myTree->HitTest(point);
// wxTreeItemId aID = myTree->GetSelection();
myTree->SelectItem(aID);
AdeModelElement* aElement = myTree->GetItem(aID);

if(((aElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_FILES) && (aElement->GetLabel()=="manual"))
{
	wxFileName parentPath = aElement->GetFileName();	
	for(unsigned int i=0; i<filenames.GetCount(); i++)
	{
		wxFileName aFile(filenames[i]);
		parentPath.SetFullName(aFile.GetFullName());
//		if (parentPath.FileExists())
//		{
//			wxMessageDialog aDialog(this,"File already exists. Overwrite?","Copy file:",wxOK | wxCANCEL | wxICON_EXCLAMATION );
//			if (aDialog.ShowModal() == wxID_CANCEL)
//				return;
//		}
		wxCopyFile(aFile.GetFullPath(), parentPath.GetFullPath());
	}

	UpdateSubtree(aID);

	retVal = true;
}

return retVal;