//~~ void StatechartCoderPathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read(wxS("Tools/StatechartCoder")));

const wxString& dir = wxFileSelector(wxS("Set Statechart Coder"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString, wxS("*"), 0, this);
wxFileName filename(dir);

if (!dir.empty())
	statechartCoderPathTextControl->SetValue(filename.GetFullPath());

theConfig->Write(wxS("Tools/StatechartCoder"), statechartCoderPathTextControl->GetValue());
