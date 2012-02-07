//~~ void CompositeStructurePathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName(theConfig->Read(wxS("Tools/CompositeStructureViewPath")));

const wxString& dir = wxFileSelector(wxS("Set Composit structure drawer path"), theFileName.GetPath(), theFileName.GetFullName(), wxEmptyString, wxS("*"), 0, this);
wxFileName filename(dir);

if (!dir.empty())
	compositeStructurePathTextControl->SetValue(filename.GetFullPath());
