if (!theFilenameList.empty())
{
	wxFileName theName(theFilenameList.front());

	if (theName.GetExt()!="ini")
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
		case ITEM_IS_ATTRIBUTES:
			return new AdeAttributes(theName);
		case ITEM_IS_ATTRIBUTE:
			return new AdeAttribute(theName);
		case ITEM_IS_CLASSES:
			return new AdeClasses(theName);
		case ITEM_IS_CLASS:
			return new AdeClass(theName);
		case ITEM_IS_COMPONENTS:
			return new AdeComponents(theName);
		case ITEM_IS_COMPONENT:
			return new AdeComponent(theName);
		case ITEM_IS_FILES:
			return new AdeFiles(theName);
		case ITEM_IS_OPERATIONS:
			return new AdeOperations(theName);
		case ITEM_IS_RELATIONS:
			return new AdeRelations(theName);
		case ITEM_IS_PACKAGE:
			return new AdePackage(theName);
		case ITEM_IS_TYPES:
			return new AdeTypes(theName);
	}
	return new AdeModelElement(theName);
}

return new AdeModelElement(wxFileName());