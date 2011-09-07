wxFileName aFile(currentFile);

const wxString& dir = wxFileSelector( wxS("Save Text"),
                                      aFile.GetPath(),
                                      wxEmptyString,
                                      wxS("seq"),
                                      wxS("*.seq"),
#if wxCHECK_VERSION(2,8,0)
                                      wxFD_OVERWRITE_PROMPT | wxFD_SAVE,
#else
                                      wxOVERWRITE_PROMPT | wxSAVE,
#endif
                                      this);

if (!dir.empty())
{
	currentFile = dir;
	if (isChanged)
		SetTitle(wxString(wxS("* ")) + currentFile);
	else
		SetTitle(currentFile);
	Save(event);
}
