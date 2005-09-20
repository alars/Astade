wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/CodeEdit"));

const wxString& dir = wxFileSelector("Set code editor",theFileName.GetPath(),theFileName.GetFullName());
wxFileName filename(dir);

if ( !dir.empty() )
{
	codeEditPathTextControl.SetValue(filename.GetFullPath());
}

