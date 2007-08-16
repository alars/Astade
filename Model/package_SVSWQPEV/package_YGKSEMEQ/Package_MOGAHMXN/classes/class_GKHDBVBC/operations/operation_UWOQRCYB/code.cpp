if (eventId == ID_ADDCLASSES)
	return AdeClasses::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();