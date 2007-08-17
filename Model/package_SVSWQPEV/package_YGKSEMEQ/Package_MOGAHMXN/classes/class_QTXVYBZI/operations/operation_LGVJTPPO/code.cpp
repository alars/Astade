if (eventId == ID_ADDCOMPONENTFOLDER)
	return AdeComponents::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();