//~~ void OnChooseIcon(wxCommandEvent& event) [AstadeAppDialog] ~~

wxFileName theFilename = wxFileName(txtIcon->GetValue());

const wxString& aFile = wxFileSelector(wxS("Select the icon"), theFilename.GetPath(), theFilename.GetFullName(), wxS("*.*"), wxS("All icon files|*.ico,*.bmp,*.png,*.jpg,*.gif,*.xpm,*.xbm|All files (*.*)|*.*"), 0, this);
if (!aFile.IsEmpty())
	txtIcon->SetValue(aFile);
