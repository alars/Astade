//~~ wxFileName AddSubElement(int eventId) [AstadePorts] ~~

if (eventId == ID_ADDPORT)
	return AdePort::CreateNewElement(myModelElement->GetFileName());
else
	return wxFileName();