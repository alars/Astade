const wxString& dir = wxFileSelector("File to open","","","","*.seq",0,this);

if ( !dir.empty() )
{
	dataBase->Clear();

	wxTextFile aFile(dir);
	aFile.Open();

	wxString str;

	for ( str = aFile.GetFirstLine(); !aFile.Eof(); str = aFile.GetNextLine() )
	    dataBase->AddLine(str);

	Refresh();
}

