if (!theFilenameList.empty())
{
	wxFileName theName(theFilenameList.front());

	if (theName.GetFullName()!="Desktop.ini")
	{
		if (theName.GetExt()=="cpp")
			return new AdeSourceFile(theName);

		if (theName.GetExt()=="h")
			return new AdeSourceFile(theName);

		return new AdeFile(theName);
	}

	theName.MakeAbsolute();
	wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,theName.GetFullPath());

	int	theType;
	theConfig.Read("Astade/Type",&theType);
	theType &= 0xFF00000;

	switch (theType)
	{
		case ITEM_IS_COMPONENTS:
			return new AdeComponents(theName);
		case ITEM_IS_COMPONENT:
			return new AdeComponent(theName);
		case ITEM_IS_FILES:
			return new AdeFiles(theName);
		case ITEM_IS_PACKAGE:
			return new AdePackage(theName);
	}
	return new AdeModelElement(theName);
}

return new AdeModelElement(wxFileName());