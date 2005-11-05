wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/Make"));

const wxString& dir = wxFileSelector("Set make",theFileName.GetPath(),theFileName.GetFullName(),"","*.*",0,this);

wxFileName filename(dir);

if ( !dir.empty() )
{
	makePathTextControl->SetValue(filename.GetFullPath());
}

