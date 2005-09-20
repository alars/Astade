wxConfigBase* theConfig = wxConfigBase::Get();
const wxString& dir = wxFileSelector("Set make",theConfig->Read("Tools/Make"));
wxFileName filename(dir);

if ( !dir.empty() )
{
	makePathTextControl.SetValue(filename.GetFullPath());
}

