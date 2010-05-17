//~~ wxFileName AddSubElement(int eventId) [AstadeClasses] ~~
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

	case ID_ADDMANUALCLASS:
	{
		wxFileName theClass = AdeClass::CreateNewElement(myModelElement->GetFileName());
		AdeClass(theClass).SetIsManualClass();
		return theClass;
	}

	default:
	return wxFileName();
}
