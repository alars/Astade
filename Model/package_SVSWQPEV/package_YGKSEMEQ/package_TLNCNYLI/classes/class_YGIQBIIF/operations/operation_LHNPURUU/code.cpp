AdeModelElement* theElement = AdeModelElement::CreateNewElement(elementFileName);

if (theElement)
{
	int iconIndex = theElement->GetIconIndex();
	AstadeIconEvent aEvent(theID,iconIndex);
	Astade::me->GetMyFrame()->AddPendingEvent(aEvent);
	delete theElement;
}
return 0;