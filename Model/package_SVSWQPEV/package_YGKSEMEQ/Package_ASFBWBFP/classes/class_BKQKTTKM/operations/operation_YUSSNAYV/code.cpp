wxFileName aFile(currentFile);

const wxString& dir = wxFileSelector( _T("Save Diagram"),
                                      aFile.GetPath(),
                                      wxEmptyString,
                                      _T("ucm"),
                                      _T("*.ucm"),
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
		SetTitle(wxString("* ") + currentFile);
	else
		SetTitle(currentFile);
	Save(event);
}
