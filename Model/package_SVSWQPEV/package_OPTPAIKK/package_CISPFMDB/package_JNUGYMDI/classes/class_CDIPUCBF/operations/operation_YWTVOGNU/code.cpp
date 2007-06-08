wxFileName newFilename = GuessGoodDirname("statechart_" + GetName());

if (GetFileName() != newFilename)
{
	newFilename.SetFullName(wxEmptyString);

	wxFileName oldFileName(GetFileName());
	oldFileName.SetFullName(wxEmptyString);

	wxFileName newParent(GetFileName());
	newParent.RemoveLastDir();

	AdeElementIterator it;

	//prepare myself;
	wxFileName savedFilename(GetFileName());
	myFileName = newFilename;
	Move_Prepare(newParent);

	bool retVal = AdeRevisionControlBase::GetRevisionControlObject()->Move(oldFileName,newFilename);

	if(retVal == 0)
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