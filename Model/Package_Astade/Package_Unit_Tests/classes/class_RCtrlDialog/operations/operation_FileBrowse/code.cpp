wxFileName theFileName(fileName->GetValue());

const wxString& dir = wxFileSelector("Select file",theFileName.GetPath(),theFileName.GetFullName(),"","*",0,this);

wxFileName filename(dir);

if ( !dir.empty() )
	fileName->SetValue(filename.GetFullPath());