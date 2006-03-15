wxFileName aFile(currentFile);

const wxString& dir = wxFileSelector("Save Text",aFile.GetPath(),wxEmptyString,"seq","*.seq",wxOVERWRITE_PROMPT|wxSAVE,this);

if (!dir.empty())
{
	currentFile = dir;
	SetTitle(currentFile);
	Save(event);
}
