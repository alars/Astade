switch(eventId)
{
	case ID_ADDOPERATION:
	return AdeOperation::CreateNewElement(myModelElement->GetFileName());

	case ID_ADDCONSTRUCTOR:
	return AdeConstructor::CreateNewElement(myModelElement->GetFileName());

	case ID_ADDDESTRUCTOR:
	return AdeDestructor::CreateNewElement(myModelElement->GetFileName());

	default:
	return wxFileName();
}