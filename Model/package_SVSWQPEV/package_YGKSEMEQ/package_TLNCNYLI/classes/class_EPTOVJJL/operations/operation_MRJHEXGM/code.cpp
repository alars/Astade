long type = anElement.GetType();

switch (type & ITEM_TYPE_MASK)
{
	//Go recursive into, in this cases:

	case ITEM_IS_MODEL:
	case ITEM_IS_COMPONENTS:
	for (AdeElementIterator it = anElement.begin(); it != anElement.end(); ++it)
	{
		AdeModelElement* element = it.CreateNewElement();
		AdeDirectoryElement* aDirElement = dynamic_cast<AdeDirectoryElement*>(element);

		if (aDirElement)
			ScanForRename(*aDirElement);

		delete element;
	}

	// ask the element to rename itself
	anElement.Rename();
	break;
}
