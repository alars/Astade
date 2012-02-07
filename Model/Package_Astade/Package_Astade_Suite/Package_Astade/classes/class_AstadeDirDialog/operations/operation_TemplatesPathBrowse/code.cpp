//~~ void TemplatesPathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
const wxString& dir = wxDirSelector(wxS("Set templates path"), theConfig->Read(wxS("TreeView/TemplatesPath")), wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
wxFileName filename(dir);

if (!dir.empty())
	templatesPathTextControl->SetValue(filename.GetFullPath());
