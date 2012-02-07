//~~ void OnChooseExt(wxCommandEvent& event) [AstadeAppDialog] ~~

const wxString& aFile = wxFileSelector(wxS("Select a file to take the filetype from"), wxEmptyString, wxEmptyString, wxS("*.*"), wxS("All files (*.*)|*.*"), 0, this);
if (!aFile.IsEmpty())
	txtExt->SetValue(wxFileName(aFile).GetExt());
