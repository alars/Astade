wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/SequencesPath"));

const wxString& dir = wxFileSelector("Set Sequences Path",theFileName.GetPath(),theFileName.GetFullName(),"","*",0,this);
wxFileName filename(dir);

if ( !dir.empty() )
{
	sequencesPathTextControl->SetValue(filename.GetFullPath());
}

