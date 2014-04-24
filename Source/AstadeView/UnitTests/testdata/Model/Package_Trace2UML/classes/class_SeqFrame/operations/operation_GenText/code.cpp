if (event.GetSelection()==1)
{
	int eventsCount = dataBase->GetEventsCount();

	textTab->Clear();

	for (int i = 0; i < eventsCount; i++)
	{
		textTab->AppendText(dataBase->GetEventText(i));
	}
	if (!isChanged)
		textTab->DiscardEdits();
}
if (event.GetOldSelection()==1)
{
	dataBase->Clear();

	for ( int i = 0; i < textTab->GetNumberOfLines(); i++ )
	    dataBase->AddLine(textTab->GetLineText(i));
	if (textTab->IsModified())
		isChanged = true;
}