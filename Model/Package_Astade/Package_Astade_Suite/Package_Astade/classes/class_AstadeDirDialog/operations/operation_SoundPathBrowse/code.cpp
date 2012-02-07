//~~ void SoundPathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read(wxS("TreeView/BuildSound")));

const wxString& dir = wxFileSelector(wxS("Set make sound"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString, wxS("*"), 0, this);

wxFileName filename(dir);

if (!dir.empty())
	soundPathTextControl->SetValue(filename.GetFullPath());
