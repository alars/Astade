const wxString& dir = wxDirSelector("Set Modelpath");
wxFileName filename(dir);

if ( !dir.empty() )
{
	modelPathTextControl.SetValue(filename.GetFullPath());
}

