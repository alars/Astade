//~~ void UseCasePathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read(wxS("Tools/UseCasesPath")));

const wxString& dir = wxFileSelector(wxS("Set use case diagram viewer Path"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString, wxS("*"), 0, this);
wxFileName filename(dir);

if (!dir.empty())
	usecasePathTextControl->SetValue(filename.GetFullPath());
