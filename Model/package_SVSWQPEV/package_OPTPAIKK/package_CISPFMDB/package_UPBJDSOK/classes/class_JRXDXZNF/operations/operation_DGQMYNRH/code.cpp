long type = anElement.GetType();

switch (type & ITEM_TYPE_MASK)
{
	//Go recursive into, in this cases:

	case ITEM_IS_COMPONENTS:
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
	case ITEM_IS_CLASSES:
	case ITEM_IS_PACKAGE:
	{
		wxString guid = anElement.GetGUID();
		while (myCacheMemory.find(guid) != myCacheMemory.end())
		{
			wxLogError(	"Die GUID %s is found twice\n"
						"In file: %s\n"
						"and in file %s\n"
						"Astade is going to repair this, "
						"giving %s a new random GUID",guid.c_str(),myCacheMemory[guid].GetFullPath().c_str(),anElement.GetFileName().GetFullPath().c_str(),anElement.GetFileName().GetFullPath().c_str());
			guid = anElement.SetGUID();
		}
		myCacheMemory[guid] = anElement.GetFileName();
	}
	break;
}
