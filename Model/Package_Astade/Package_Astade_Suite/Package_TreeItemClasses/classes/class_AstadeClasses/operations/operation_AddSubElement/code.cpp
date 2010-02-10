switch (eventId)
{
	case ID_ADDCLASS:
	return AdeClass::CreateNewElement(myModelElement->GetFileName());

	case ID_ADDSTATECHART:
	return AdeStatechart::CreateNewElement(myModelElement->GetFileName());

	case ID_ADDLIBCLASS:
	{
		wxFileName theClass = AdeClass::CreateNewElement(myModelElement->GetFileName());
		AdeClass(theClass).SetIsLibClass();
		return theClass;
	}

	default:
	return wxFileName();
}