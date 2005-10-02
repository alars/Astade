wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/Coder"));

const wxString& dir = wxFileSelector("Set Coder",theFileName.GetPath(),theFileName.GetFullName(),"","*.*",0,this);
wxFileName filename(dir);

if ( !dir.empty() )
{
	coderPathTextControl.SetValue(filename.GetFullPath());
}

