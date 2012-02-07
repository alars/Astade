//~~ void SequencesPathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read(wxS("Tools/SequencesPath")));

const wxString& dir = wxFileSelector(wxS("Set Sequences Path"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString, wxS("*"), 0, this);
wxFileName filename(dir);

if (!dir.empty())
	sequencesPathTextControl->SetValue(filename.GetFullPath());

