//~~ wxFileName AddSubElement(int eventId) [AstadeStatechart] ~~
if (eventId == ID_ADDSTATE)
	return AdeState::CreateNewElement(myModelElement->GetFileName());
else if (eventId == ID_ADDTRANSITION)
	return AdeTransition::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();