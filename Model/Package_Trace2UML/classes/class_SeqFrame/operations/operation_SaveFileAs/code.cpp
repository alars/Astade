//~~ void SaveFileAs(wxCommandEvent& event) [SeqFrame] ~~

wxFileName aFile(currentFile);

const wxString& dir = wxFileSelector( wxS("Save Text"),
                                      aFile.GetPath(),
                                      wxEmptyString,
                                      wxS("seq"),
                                      wxS("*.seq"),
                                      wxFD_OVERWRITE_PROMPT | wxFD_SAVE,
                                      this);

if (!dir.empty())
{
	currentFile = dir;
	if (isChanged)
		SetTitle(wxS("* ") + currentFile);
	else
		SetTitle(currentFile);
	Save(event);
}
