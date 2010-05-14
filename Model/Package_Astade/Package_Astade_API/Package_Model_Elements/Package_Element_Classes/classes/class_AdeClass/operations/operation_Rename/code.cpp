wxFileName newFilename = GuessGoodDirname(wxS("class_") + GetName());

if (GetFileName() != newFilename)
{
	newFilename.SetFullName(wxEmptyString);

	wxFileName oldFileName(GetFileName());
	oldFileName.SetFullName(wxEmptyString);

	wxFileName newParent(newFilename);
	newParent.RemoveLastDir();
	newParent.SetFullName(wxEmptyString);

	wxFileName savedFilename(GetFileName());

	// prepare all the childs
	for (AdeElementIterator it = begin(); it != end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		anElement->Move_Prepare(newFilename);
		delete anElement;
	}

	RemoveComponentEntrys();
	myFileName = newFilename;

	int retVal = AdeRevisionControlBase::GetRevisionControlObject()->Move(oldFileName, newFilename);

	if (retVal == 0)
	{
		myFileName.SetFullName(wxS("ModelNode.ini"));
		Move_Complete(newParent);
	}
	else
	{
		myFileName = savedFilename;
		Move_Rollback();
	}
}
