if (eventId == ID_ADDSTATE)
	return AdeState::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();