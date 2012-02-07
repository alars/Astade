//~~ void StatechartViewPathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read(wxS("Tools/StatechartViewPath")));

const wxString& dir = wxFileSelector(wxS("Set Statechart viewer Path"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString, wxS("*"), 0, this);
wxFileName filename(dir);

if (!dir.empty())
	statechartPathTextControl->SetValue(filename.GetFullPath());

