switch (eventId)
{
	case ID_ADDCLASSES:
	return AdeClasses::CreateNewElement(myModelElement->GetFileName());

	case ID_ADDPACKAGE:
	return AdePackage::CreateNewElement(myModelElement->GetFileName());

	default:
	return wxFileName();
}