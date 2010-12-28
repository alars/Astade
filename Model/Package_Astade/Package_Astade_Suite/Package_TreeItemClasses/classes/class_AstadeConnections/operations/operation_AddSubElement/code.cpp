//~~ wxFileName AddSubElement(int eventId) [AstadeConnections] ~~

if (eventId == ID_ADDCONNECTION)
	return AdeConnection::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();