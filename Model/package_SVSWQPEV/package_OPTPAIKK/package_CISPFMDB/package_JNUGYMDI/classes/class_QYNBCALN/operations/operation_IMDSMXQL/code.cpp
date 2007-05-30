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

	if(retVal == 0)
	{
		myFileName = newFilename;
		for (it=begin();it!=end();++it)
		{
			AdeModelElement* aElement = it.CreateNewElement();
			aElement->Move_Complete(newFilename);
			delete(aElement);
		}
	}
	else
	{
		for (it=begin();it!=end();++it)
		{
			AdeModelElement* aElement = it.CreateNewElement();
			aElement->Move_Unprepare();
			delete(aElement);
		}
	}
}