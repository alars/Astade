long type = anElement.GetType();
static AdeModel* theModel = 0;

switch (type & ITEM_TYPE_MASK)
{
	//Go recursive into, in this cases:

	case ITEM_IS_MODEL:
		theModel = dynamic_cast<AdeModel*>(&anElement);
	case ITEM_IS_COMPONENTS:
	case ITEM_IS_COMPONENT:
	case ITEM_IS_PACKAGE:
	case ITEM_IS_CLASSES:
	case ITEM_IS_CLASS:
	case ITEM_IS_OPERATIONS:
	for (AdeElementIterator it = anElement.begin(); it != anElement.end(); ++it)
	{
		AdeModelElement* element = it.CreateNewElement();
		AdeDirectoryElement* aDirElement = dynamic_cast<AdeDirectoryElement*>(element);

		if (aDirElement)
			ScanForRename(*aDirElement);

		delete element;
	}
	anElement.Rename();
	break;

	case ITEM_IS_CONFIGURATION:
	anElement.Rename();
	AdeGUIDCache::Instance()->Load(*theModel);
	break;
}
