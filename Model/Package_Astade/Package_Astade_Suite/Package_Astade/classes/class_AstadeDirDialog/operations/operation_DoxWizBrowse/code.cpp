//~~ void DoxWizBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read(wxS("Tools/DoxWiz")));

const wxString& dir = wxFileSelector(wxS("Set Doxygen Wizard"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString, wxS("*"), 0, this);
wxFileName filename(dir);

if (!dir.empty())
	DoxWizTextControl->SetValue(filename.GetFullPath());
