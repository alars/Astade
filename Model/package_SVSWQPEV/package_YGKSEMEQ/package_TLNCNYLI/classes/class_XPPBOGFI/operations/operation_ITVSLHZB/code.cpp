const wxString& dir = wxFileSelector("Set make");
wxFileName filename(dir);

if ( !dir.empty() )
{
	makePathTextControl.SetValue(filename.GetFullPath());
}

