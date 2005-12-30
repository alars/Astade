const wxString& dir = wxFileSelector("Save to","","","","*.seq",0,this);

if ( !dir.empty() )
{
	currentFile = dir;
	SetTitle(currentFile);
	Save(event);
}
