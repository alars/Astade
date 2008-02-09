// TextTab
if (event.GetSelection() == 1)
{
	GetMenuBar()->EnableTop(GetMenuBar()->FindMenu(_T("&Edit")), false);

	int eventsCount = dataBase->GetEventsCount();

    wxString Buffer;
    textTab->Clear();
    
	for (int i = 0; i < eventsCount; i++)
	{
		//textTab->AppendText(dataBase->GetEventText(i));
        Buffer += dataBase->GetEventText(i);
	}
    
    textTab->SetDefaultStyle();
    textTab->WriteText(Buffer);
    textTab->SetStyle();
    
	if (!isChanged)
		textTab->DiscardEdits();
}

//GrafTab
if (event.GetOldSelection() == 1)
{
	GetMenuBar()->EnableTop(GetMenuBar()->FindMenu(_T("&Edit")), true);

	dataBase->Clear();

	for (int i = 0; i < textTab->GetNumberOfLines(); i++)
	    dataBase->AddLine(textTab->GetLineText(i));
	if (textTab->IsModified())
		isChanged = true;
}
