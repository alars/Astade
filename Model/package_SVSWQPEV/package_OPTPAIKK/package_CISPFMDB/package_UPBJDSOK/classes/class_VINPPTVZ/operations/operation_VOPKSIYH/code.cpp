if (!theFilenameList.empty())
{
	wxFileName theName(theFilenameList.front());

	if (theName.GetFullName()!="Desktop.ini")
		return new AdeFile(theName);

	theName.MakeAbsolute();
	wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,theName.GetFullPath());

	int	theType;
	theConfig.Read("Astade/Type",&theType);
	theType &= 0xFF00000;

	switch (theType)
	{
		case ITEM_IS_COMPONENTS:
			return new AdeComponents(theName);
	}
	return new AdeModelElement(theName);
}

return new AdeModelElement(wxFileName());