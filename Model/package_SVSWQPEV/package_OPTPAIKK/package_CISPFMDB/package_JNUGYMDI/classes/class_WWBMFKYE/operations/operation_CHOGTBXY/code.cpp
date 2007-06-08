wxFileName newFilename = GuessGoodDirname("class_" + GetName());

if (GetFileName() != newFilename)
{
	newFilename.SetFullName(wxEmptyString);

	wxFileName oldFileName(GetFileName());
	oldFileName.SetFullName(wxEmptyString);

	wxFileName newParent(newFilename);
	newParent.RemoveLastDir();

	AdeElementIterator it;

	//prepare myself;
	Move_Prepare(newParent);

	bool retVal = AdeRevisionControlBase::GetRevisionControlObject()->Move(oldFileName,newFilename);

	if(retVal == 0)
	{
		myFileName = newFilename;
		myFileName.SetFullName("ModelNode.ini");
		Move_Complete(newParent);
	}
	else
	{
		Move_Unprepare();
	}
}