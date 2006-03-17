wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read("TreeView/BuildSound"));

const wxString& dir = wxFileSelector("Set make sound",theFileName.GetPath(),theFileName.GetFullName(),"","*",0,this);

wxFileName filename(dir);

if ( !dir.empty() )
	soundPathTextControl->SetValue(filename.GetFullPath());