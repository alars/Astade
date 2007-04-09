AdeModelElement* theElement = AdeModelElement::CreateNewElement(elementFileName);

if (theElement)
{
	int iconIndex = theElement->GetIconIndex();
	AstadeIconEvent aEvent(theID,iconIndex);
	wxFrame* theFrame;
	while (!(theFrame = Astade::me->GetMyFrame()))
		wxMilliSleep(10);
	theFrame->AddPendingEvent(aEvent);
	delete theElement;
}
return 0;
