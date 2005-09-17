const wxString& dir = wxFileSelector("Set OMD viewer");
wxFileName filename(dir);

if ( !dir.empty() )
{
	omdPathTextControl.SetValue(filename.GetFullPath());
}

