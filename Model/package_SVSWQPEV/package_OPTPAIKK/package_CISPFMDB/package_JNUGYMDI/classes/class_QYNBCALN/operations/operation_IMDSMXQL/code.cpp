wxFileName newFilename = GuessGoodDirname("Package_" + GetName());

if (GetFileName() != newFilename)
{
	newFilename.SetFullName(wxEmptyString);

	wxFileName oldFileName(GetFileName());
	oldFileName.SetFullName(wxEmptyString);

	wxFileName newParent(newFilename);
	newParent.RemoveLastDir();
	newParent.SetFullName(wxEmptyString);

	wxFileName savedFilename(GetFileName());

	AdeElementIterator it;

	// prepare all the childs
	for (it = begin(); it != end(); ++it)
	{
		AdeModelElement* aElement = it.CreateNewElement();
		aElement->Move_Prepare(newFilename);
		delete(aElement);
	}

	myFileName = newFilename;

	bool retVal = AdeRevisionControlBase::GetRevisionControlObject()->Move(oldFileName,newFilename);

	if (retVal == 0)
	{
		myFileName.SetFullName("ModelNode.ini");
		Move_Complete(newParent);
	}
	else
	{
		myFileName = savedFilename;
		Move_Unprepare();
	}
}
