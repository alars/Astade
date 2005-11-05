wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/CodeEdit"));

const wxString& dir = wxFileSelector("Set code editor",theFileName.GetPath(),theFileName.GetFullName(),"","*.*",0,this);
wxFileName filename(dir);

if ( !dir.empty() )
{
	codeEditPathTextControl->SetValue(filename.GetFullPath());
}

