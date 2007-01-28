/* vi: set tabstop=4: */

if (theUpdateItemList.empty())
	return;

wxTreeItemId theID = theUpdateItemList.front();
theUpdateItemList.pop_front();

AdeModelElement* theElement = GetItem(theID);

if (theElement)
{
	if(theElement->GetType() & ITEM_IS_FILE)
	{		
		std::map<wxString, int>::iterator iter =
			myUserAppIcons.find((theElement->GetFileName()).GetExt());
		if(iter != myUserAppIcons.end())
		{
			SetItemImage(theID, iter->second);
		}
		else
		{
			SetItemImage(theID, theElement->GetIconIndex());
		}
	}
	else
	{
		SetItemImage(theID, theElement->GetIconIndex());
	}

	wxFont theFont = GetItemFont(theID);

#ifdef __WXMAC__
	if (theFont.GetPointSize() < 14)
		theFont.SetPointSize(14);
#endif

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
	SetItemText(theID,";-)"); //This is neccessary because when setting the same text again, wxWidgets doesn't calculate the Textsize even if it's bold now.
	SetItemText(theID,theElement->GetLabel());
}
