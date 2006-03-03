AdeModelElement* theElement = GetItem(theID);

if (theElement)
{
	SetItemImage(theID,theElement->GetIconIndex());

    wxFont theFont = GetItemFont(theID);

    if ( 14 > theFont.GetPointSize() )
        theFont.SetPointSize( 14 );

    if (theElement->GetLabelIsUnderlined())
		theFont.SetUnderlined(true);
	else
		theFont.SetUnderlined(false);

    if (theElement->GetLabelIsBold())
		theFont.SetWeight(wxBOLD);
	else
		theFont.SetWeight(wxNORMAL);

    if (theElement->GetLabelIsItalic())
		theFont.SetStyle(wxITALIC);
	else
		theFont.SetStyle(wxNORMAL);

	SetItemHasChildren(theID,theElement->GetHasChildren());
	SetItemFont(theID,theFont);
	SetItemText(theID,";-)"); //This is neccessary, because, when setting the same text again, wxWidgets doesn't calculate the Textsize, even if ist bold now.
	SetItemText(theID,theElement->GetLabel());

}
