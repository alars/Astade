const wxString& dir = wxFileSelector("Set Helpfile");
wxFileName filename(dir);

if ( !dir.empty() )
{
	helpPathTextControl.SetValue(filename.GetFullPath());
}

