if (eventId == ID_ADDTRANSITION)
	return AdeTransition::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();