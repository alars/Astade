wxFileName newFilename = GuessGoodDirname("package_" + GetName());

if (GetFileName() != newFilename)
{
	newFilename.SetFullName(wxEmptyString);
	wxFileName oldFileName(GetFileName());
	oldFileName.SetFullName(wxEmptyString);


	AdeElementIterator it;

	// prepare all the childs
	for (it=begin();it!=end();++it)
	{
		AdeModelElement* aElement = it.CreateNewElement();
		aElement->Move_Prepare(newFilename);
		delete(aElement);
	}

	bool retVal = AdeRevisionControlBase::GetRevisionControlObject()->Move(oldFileName,newFilename);

	if(retVal)
	{
		AdeModelElement* aElement = it.CreateNewElement();
		aElement->Move_Complete(newFilename);
		delete(aElement);
	}
	else
	{
		AdeModelElement* aElement = it.CreateNewElement();
		aElement->Move_Unprepare();
		delete(aElement);
	}
}