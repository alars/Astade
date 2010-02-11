if ( !dir.empty() )
{
	currentFile = dir;
	wxTextFile aTextFile(currentFile);

	dataBase->Clear();

	if (aTextFile.Exists())
	{
		aTextFile.Open();

		if (aTextFile.IsOpened())
		{
			wxString str;

			for ( str = aTextFile.GetFirstLine(); !aTextFile.Eof(); str = aTextFile.GetNextLine() )
			{
				dataBase->AddLine(str);
			}
			dataBase->AddLine(str);

			if (noteBook->GetSelection()==1)
			{
				textTab->Clear();
				int eventsCount = dataBase->GetEventsCount();

				for (int i = 0; i < eventsCount; i++)
				{
					textTab->AppendText(dataBase->GetEventText(i));
				}
			}
		}
		else
		{
			currentFile.clear();
		}
	}
	graphTab->Refresh();
	SetTitle(currentFile);
	isChanged = false;
}