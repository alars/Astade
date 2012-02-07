//~~ void OnChooseApp(wxCommandEvent& event) [AstadeAppDialog] ~~

wxFileName theFilename = wxFileName(txtApp->GetValue());

const wxString& aFile = wxFileSelector(wxS("Select the application executable"), theFilename.GetPath(), theFilename.GetFullName(), wxS("*.*"), wxS("All files (*.*)|*.*"), 0, this);
if (!aFile.IsEmpty())
	txtApp->SetValue(aFile);
