#if !defined(wxS)
#  define wxS(x) wxT(x)
#endif

wxFileName aFile(currentFile);

const wxString& dir = wxFileSelector( wxS("Save Diagram"),
                                      aFile.GetPath(),
                                      wxEmptyString,
                                      wxS(""),
                                      wxS("*"),
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
	Save();
}
