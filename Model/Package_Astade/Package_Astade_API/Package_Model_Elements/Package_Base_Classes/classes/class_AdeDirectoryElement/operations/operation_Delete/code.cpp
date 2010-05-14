for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	anElement->Delete();
	delete anElement;
}

myFileName.SetFullName(wxEmptyString);
AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

theRevisionControl->Delete(myFileName);
