if (!theFilenameList.empty())
{
	wxFileName theName(theFilenameList.front());

	if (theName.GetExt()!="ini")
	{
		if (theName.GetName()=="Makefile")
			return new AdeMake(theName);

		if (theName.GetExt()=="cpp")
			return new AdeSourceFile(theName);

		if (theName.GetExt()=="h")
			return new AdeSourceFile(theName);

		return new AdeFile(theName);
	}

	theName.MakeAbsolute();
	wxFileConfig theConfig(wxEmptyString,wxEmptyString,theName.GetFullPath());

	int	theType;
	theConfig.Read("Astade/Type",&theType);

	switch (theType & 0xFF00000)
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
		case ITEM_IS_CONFIGURATION:
			return new AdeConfiguration(theName);
		case ITEM_IS_FILES:
			return new AdeFiles(theName);
		case ITEM_IS_OPERATIONS:
			return new AdeOperations(theName);
		case ITEM_IS_OPERATION:
			if (theType & ITEM_IS_NORMALOP)
				return new AdeOperation(theName);
			else
			if (theType & ITEM_IS_DEST)
				return new AdeDestructor(theName);
			else
				return new AdeConstructor(theName);
		case ITEM_IS_PARAMETERS:
			return new AdeParameters(theName);
		case ITEM_IS_PARAMETER:
			return new AdeParameter(theName);
		case ITEM_IS_RELATIONS:
			return new AdeRelations(theName);
		case ITEM_IS_RELATION:
			return new AdeRelation(theName);
		case ITEM_IS_INRELATION:
			return new AdeInRelation(theName);
		case ITEM_IS_PACKAGE:
			return new AdePackage(theName);
		case ITEM_IS_TYPES:
			return new AdeTypes(theName);
		case ITEM_IS_TYPE:
			return new AdeType(theName);
	}
	return new AdeModelElement(theName);
}

return new AdeModelElement(wxFileName());