// vi: set tabstop=4:
if (theFileName.GetExt() != "ini")
{
	if (theFileName.GetName() == "Makefile")
		return new AdeMake(theFileName);

	if (theFileName.GetExt() == "cpp")
		return new AdeSourceFile(theFileName);

	if (theFileName.GetExt() == "h")
		return new AdeSourceFile(theFileName);

	return new AdeFile(theFileName);
}

int theType = AdeModelElement(theFileName).GetType();
switch (theType & 0xFF00000)
{
	case ITEM_IS_ATTRIBUTES:
		return new AdeAttributes(theFileName);

	case ITEM_IS_ATTRIBUTE:
		return new AdeAttribute(theFileName);

	case ITEM_IS_CLASSES:
		return new AdeClasses(theFileName);

	case ITEM_IS_CLASS:
		return new AdeClass(theFileName);

	case ITEM_IS_COMPONENTS:
		return new AdeComponents(theFileName);

	case ITEM_IS_COMPONENT:
		return new AdeComponent(theFileName);

	case ITEM_IS_CONFIGURATION:
		return new AdeConfiguration(theFileName);

	case ITEM_IS_FILES:
		return new AdeFiles(theFileName);

	case ITEM_IS_OPERATIONS:
		return new AdeOperations(theFileName);

	case ITEM_IS_OPERATION:
		if (theType & ITEM_IS_NORMALOP)
			return new AdeOperation(theFileName);
		else if (theType & ITEM_IS_DEST)
			return new AdeDestructor(theFileName);
		else
			return new AdeConstructor(theFileName);

	case ITEM_IS_PARAMETERS:
		return new AdeParameters(theFileName);

	case ITEM_IS_PARAMETER:
		return new AdeParameter(theFileName);

	case ITEM_IS_RELATIONS:
		return new AdeRelations(theFileName);

	case ITEM_IS_RELATION:
		return new AdeRelation(theFileName);

	case ITEM_IS_INRELATION:
		return new AdeInRelation(theFileName);

	case ITEM_IS_PACKAGE:
		return new AdePackage(theFileName);

	case ITEM_IS_TYPES:
		return new AdeTypes(theFileName);

	case ITEM_IS_TYPE:
		return new AdeType(theFileName);

	case ITEM_IS_STATECHART:
		return new AdeStatechart(theFileName);

	case ITEM_IS_STATE:
		return new AdeState(theFileName);

	case ITEM_IS_TRANSITION:
		return new AdeTransition(theFileName);
}
return new AdeModelElement(theFileName);
