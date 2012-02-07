//~~ void CodeEditPathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read(wxS("Tools/CodeEdit")));

const wxString& dir = wxFileSelector(wxS("Set code editor"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString,wxS("*"), 0, this);
wxFileName filename(dir);

if (!dir.empty())
	codeEditPathTextControl->SetValue(filename.GetFullPath());
