//~~ AdeModelElement* CreateNewElement(const wxFileName& theFileName) [AdeModelElement] ~~
// vi: set tabstop=4:
if (theFileName.GetExt() != wxS("ini"))
{
	if (theFileName.GetName() == wxS("Makefile"))
		return new AdeMake(theFileName);

	if (theFileName.GetName() == wxS("<unknown>"))
		return new AdeUnknown(theFileName);

	if (theFileName.GetExt() == wxS("cpp"))
		return new AdeSourceFile(theFileName);

	if (theFileName.GetExt() == wxS("h"))
		return new AdeSourceFile(theFileName);

	if (theFileName.GetExt() == wxS("dox"))
		return new AdeSourceFile(theFileName);

	if (theFileName.GetExt() == wxS("c"))
		return new AdeSourceFile(theFileName);

	if (theFileName.GetExt() == wxS("seq"))
		return new AdeSequence(theFileName);

	if (theFileName.GetExt() == wxS("ucm"))
		return new AdeUseCase(theFileName);

	if (theFileName.GetExt() == wxS("html"))
		return new AdeLocalWebsite(theFileName);

	return new AdeFile(theFileName);
}

int theType;

std::map<wxString,int>::iterator cachedType = myTypeCache.find(theFileName.GetFullPath());

if (cachedType != myTypeCache.end())
{
	theType = (*cachedType).second;
}
else
{
 	theType = AdeModelElement(theFileName).GetType();
 	myTypeCache[theFileName.GetFullPath()] = theType;
}

switch (theType & ITEM_TYPE_MASK)
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

	case ITEM_IS_SEQUENCES:
		return new AdeSequences(theFileName);

	case ITEM_IS_STATECHART:
		return new AdeStatechart(theFileName);

	case ITEM_IS_STATE:
		return new AdeState(theFileName);

	case ITEM_IS_TRANSITION:
		return new AdeTransition(theFileName);

	case ITEM_IS_USECASEDIAGRAMS:
		return new AdeUsecaseDiagrams(theFileName);

	case ITEM_IS_PORTS:
		return new AdePorts(theFileName);

	case ITEM_IS_CONNECTIONS:
		return new AdeConnections(theFileName);
}
return new AdeModelElement(theFileName);
