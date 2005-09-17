const wxString& dir = wxFileSelector("Set Coder");
wxFileName filename(dir);

if ( !dir.empty() )
{
	coderPathTextControl.SetValue(filename.GetFullPath());
}

