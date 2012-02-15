//~~ void SaveAs() [glFrame] ~~

wxFileName aFile(currentFile);

const wxString& dir = wxFileSelector( wxS("Save Diagram"),
                                      aFile.GetPath(),
                                      wxEmptyString,
                                      wxEmptyString,
                                      wxS("*"),
                                      wxFD_OVERWRITE_PROMPT | wxFD_SAVE,
                                      this);

if (!dir.empty())
{
	currentFile = dir;
	if (isChanged)
		SetTitle(wxS("* ") + currentFile);
	else
		SetTitle(currentFile);
	Save();
}
