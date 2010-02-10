wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("Tools/DoxWiz"));

const wxString& dir = wxFileSelector("Set Doxygen Wizzard",theFileName.GetPath(),theFileName.GetFullName(),"","*",0,this);
wxFileName filename(dir);

if ( !dir.empty() )
	DoxWizTextControl->SetValue(filename.GetFullPath());