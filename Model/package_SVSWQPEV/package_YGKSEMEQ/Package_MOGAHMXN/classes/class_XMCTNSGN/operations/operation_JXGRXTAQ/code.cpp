if (eventId == ID_ADDATTRIBUTES)
	return AdeAttributes::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();