wxFileName aFile(currentFile);

const wxString& dir = wxFileSelector("Save Diagram",aFile.GetPath(),wxEmptyString,"ucm","*.ucm",wxOVERWRITE_PROMPT|wxSAVE,this);

if (!dir.empty())
{
	currentFile = dir;
	if (isChanged)
		SetTitle(wxString("* ")+currentFile);
	else
		SetTitle(currentFile);
	Save(event);
}