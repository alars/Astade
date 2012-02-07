//~~ void CCoderPathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read(wxS("Tools/CCoder")));

const wxString& dir = wxFileSelector(wxS("Set C Coder"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString, wxS("*"), 0, this);
wxFileName filename(dir);

if (!dir.empty())
	ccoderPathTextControl->SetValue(filename.GetFullPath());
