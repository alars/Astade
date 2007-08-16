if (eventId == ID_ADDCLASS)
	return AdeClass::CreateNewElement(myModelElement->GetFileName());

else if (eventId == ID_ADDLIBCLASS)
{
	wxFileName theClass = AdeClass::CreateNewElement(myModelElement->GetFileName());
	AdeClass(theClass).SetIsLibClass();
	return theClass;
}
else
	return wxFileName();