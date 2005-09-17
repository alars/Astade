const wxString& dir = wxDirSelector("Set templates path");
wxFileName filename(dir);

if ( !dir.empty() )
{
	templatesPathTextControl.SetValue(filename.GetFullPath());
}
