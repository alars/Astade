//~~ void FileBrowse(wxCommandEvent& event) [RCtrlDialog] ~~

wxFileName theFileName(fileName->GetValue());

const wxString& dir = wxFileSelector(wxS("Select file"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString, wxS("*"), 0, this);

wxFileName filename(dir);

if (!dir.empty())
	fileName->SetValue(filename.GetFullPath());
