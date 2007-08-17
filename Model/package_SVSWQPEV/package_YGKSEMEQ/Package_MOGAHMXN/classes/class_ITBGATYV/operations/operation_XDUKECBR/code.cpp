if (eventId == ID_ADDCONFIGURATION)
	return AdeConfiguration::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();