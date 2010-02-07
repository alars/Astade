if (eventId == ID_ADDPARAMETER)
	return AdeParameter::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();