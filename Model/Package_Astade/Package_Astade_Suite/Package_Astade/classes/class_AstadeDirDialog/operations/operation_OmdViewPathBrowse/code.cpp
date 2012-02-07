//~~ void OmdViewPathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read(wxS("Tools/OmdViewPath")));

const wxString& dir = wxFileSelector(wxS("Set OMD viewer"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString, wxS("*"), 0, this);
wxFileName filename(dir);

if (!dir.empty())
	omdPathTextControl->SetValue(filename.GetFullPath());

