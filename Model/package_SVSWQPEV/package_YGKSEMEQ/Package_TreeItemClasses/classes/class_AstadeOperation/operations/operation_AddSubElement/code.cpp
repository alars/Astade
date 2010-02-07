if (eventId == ID_ADDPARAMETERS)
	return AdeParameters::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();