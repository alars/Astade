//~~ void MakePathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read(wxS("Tools/Make")));

const wxString& dir = wxFileSelector(wxS("Set make"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString, wxS("*"), 0, this);

wxFileName filename(dir);

if (!dir.empty())
	makePathTextControl->SetValue(filename.GetFullPath());
