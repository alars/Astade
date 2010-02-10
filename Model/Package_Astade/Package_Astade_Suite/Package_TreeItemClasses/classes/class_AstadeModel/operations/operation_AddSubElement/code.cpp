switch (eventId)
{
	case ID_ADDCOMPONENTFOLDER:
	return AdeComponents::CreateNewElement(myModelElement->GetFileName());

	case ID_ADDPACKAGE:
	return AdePackage::CreateNewElement(myModelElement->GetFileName());

	default:
	return wxFileName();
}