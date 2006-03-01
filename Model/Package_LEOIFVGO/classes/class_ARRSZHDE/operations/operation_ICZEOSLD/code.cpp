wxFileName aFile(currentFile);

//const wxString& dir = wxFileSelector("Save to",aFile.GetPath(),aFile.GetFullName(),"","*.seq",0,this);
const wxString& dir = wxFileSelector("Save to",aFile.GetPath(),wxEmptyString,"seq","*.seq",wxOVERWRITE_PROMPT|wxSAVE,this);

if ( !dir.empty() )
{
	currentFile = dir;
	SetTitle(currentFile);
	Save(event);
}
