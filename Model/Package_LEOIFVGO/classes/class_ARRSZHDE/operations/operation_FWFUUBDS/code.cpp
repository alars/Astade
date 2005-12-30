const wxString& dir = wxFileSelector("File to open","","","","*.seq",0,this);

if ( !dir.empty() )
{
	currentFile = dir;
	wxTextFile aTextFile(currentFile);
	aTextFile.Open();

	if (aTextFile.IsOpened())
	{
		wxString str;
		dataBase->Clear();

		for ( str = aTextFile.GetFirstLine(); !aTextFile.Eof(); str = aTextFile.GetNextLine() )
		{
			dataBase->AddLine(str);
		}
		dataBase->AddLine(str);

		graphTab->Refresh();

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

	SetTitle(currentFile);
}

