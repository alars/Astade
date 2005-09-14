AdeModelElement* theElement = GetItem(theID);

if (theElement)
{
	SetItemImage(theID,theElement->GetIconIndex());

    wxFont theFont = GetItemFont(theID);

    if (theElement->GetLabelIsUnderlined())
		theFont.SetUnderlined(true);
	else
		theFont.SetUnderlined(false);

    if (theElement->GetLabelIsBold())
		theFont.SetWeight(wxBOLD);
	else
		theFont.SetWeight(wxNORMAL);

    if (theElement->GetLabelIsKursiv())
		theFont.SetStyle(wxITALIC);
	else
		theFont.SetStyle(wxNORMAL);


	SetItemFont(theID,theFont);
	SetItemText(theID,theElement->GetLabel());
	SetItemHasChildren(theID,theElement->GetHasChildren());
}