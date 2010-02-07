if (eventId == ID_ADDCOMPONENT)
	return AdeComponent::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();