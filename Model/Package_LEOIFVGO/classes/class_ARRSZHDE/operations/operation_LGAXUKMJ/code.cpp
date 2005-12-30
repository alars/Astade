if (currentFile.empty())
{
	SaveFileAs(event);
	return;
}

int eventsCount = dataBase->GetEventsCount();

if (noteBook->GetSelection()!=1)
{
	textTab->Clear();

	for (int i = 0; i < eventsCount; i++)
	{
		textTab->AppendText(dataBase->GetEventText(i));
	}
}

textTab->SaveFile(currentFile);