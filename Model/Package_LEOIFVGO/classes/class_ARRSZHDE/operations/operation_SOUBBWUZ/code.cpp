int eventsCount = dataBase->GetEventsCount();

textTab->Clear();

for (int i = 0; i < eventsCount; i++)
{
	textTab->AppendText(dataBase->GetEventText(i));
}

textTab->SaveFile(currentFile);