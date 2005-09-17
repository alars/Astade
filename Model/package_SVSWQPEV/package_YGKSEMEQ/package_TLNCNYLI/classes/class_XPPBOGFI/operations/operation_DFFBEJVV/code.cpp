const wxString& dir = wxFileSelector("Set code editor");
wxFileName filename(dir);

if ( !dir.empty() )
{
	codeEditPathTextControl.SetValue(filename.GetFullPath());
}

