const wxString& dir = wxFileSelector("Set Feature editor");
wxFileName filename(dir);

if ( !dir.empty() )
{
	featureEditPathTextControl.SetValue(filename.GetFullPath());
}

