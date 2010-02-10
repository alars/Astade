if (eventId == ID_ADDATTRIBUTE)
	return AdeAttribute::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();