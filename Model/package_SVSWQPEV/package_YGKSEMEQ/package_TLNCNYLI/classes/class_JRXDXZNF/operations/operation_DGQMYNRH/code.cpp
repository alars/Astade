long type = anElement.GetType();

switch (type & ITEM_TYPE_MASK)
{
	//Go recursive into, in this cases:

	case ITEM_IS_COMPONENTS:
	case ITEM_IS_CLASSES:
	case ITEM_IS_PACKAGE:
	for (AdeElementIterator it = anElement.begin(); it != anElement.end(); ++it)
	{
		AdeModelElement* element = it.CreateNewElement();
		AdeDirectoryElement* aDirElement = dynamic_cast<AdeDirectoryElement*>(element);

		if (aDirElement)
			Include(*aDirElement);

		delete element;
	}
	//nobreak;

	// Put into Cache in this cases:
	case ITEM_IS_CLASS:
	case ITEM_IS_COMPONENT:
	case ITEM_IS_STATECHART:

		myCacheMemory[anElement.GetGUID()] = anElement.GetFileName();

	break;
}
