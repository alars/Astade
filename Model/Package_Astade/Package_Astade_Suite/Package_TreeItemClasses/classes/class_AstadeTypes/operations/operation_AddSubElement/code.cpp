if (eventId == ID_ADDTYPE)
	return AdeType::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();