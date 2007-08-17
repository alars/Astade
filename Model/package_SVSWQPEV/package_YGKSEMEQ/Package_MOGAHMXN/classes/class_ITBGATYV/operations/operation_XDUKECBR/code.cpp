switch (eventId)
{
	case ID_ADDCONFIGURATION:
	return AdeConfiguration::CreateNewElement(myModelElement->GetFileName());

	case ID_ADDSEQUENCES:
	return AdeSequences::CreateNewElement(myModelElement->GetFileName());

	default:
	return wxFileName();
}