//~~ wxFileName AddSubElement(int eventId) [AstadeClass] ~~
switch (eventId)
{
	case ID_ADDATTRIBUTES:
	return AdeAttributes::CreateNewElement(myModelElement->GetFileName());

	case ID_ADDOPERATIONS:
	return AdeOperations::CreateNewElement(myModelElement->GetFileName());

	case ID_ADDTYPES:
	return AdeTypes::CreateNewElement(myModelElement->GetFileName());

	case ID_ADDPORTS:
	return AdePorts::CreateNewElement(myModelElement->GetFileName());

	case ID_ADDCONNECTIONS:
	return AdeConnections::CreateNewElement(myModelElement->GetFileName());

	default:
	return wxFileName();
}