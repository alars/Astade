wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("TreeView/Helpfile"));

const wxString& dir = wxFileSelector("Set Helpfile",theFileName.GetPath(),theFileName.GetFullName());
wxFileName filename(dir);

if ( !dir.empty() )
{
	helpPathTextControl.SetValue(filename.GetFullPath());
}

