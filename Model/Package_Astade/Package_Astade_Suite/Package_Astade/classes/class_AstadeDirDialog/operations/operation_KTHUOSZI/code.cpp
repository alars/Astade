//~~ void PythonCoderPathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read(wxS("Tools/PythonCoder")));

const wxString& dir = wxFileSelector(wxS("Set Python Coder"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString, wxS("*"), 0, this);
wxFileName filename(dir);

if (!dir.empty())
	pythoncoderPathTextControl->SetValue(filename.GetFullPath());
