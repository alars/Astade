//~~ void ModelPathBrowse(wxCommandEvent& event) [AstadeDirDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
const wxString& dir = wxDirSelector(wxS("Open Model"), theConfig->Read(wxS("TreeView/ModelPath")), wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

if (!dir.empty())
{
	wxConfigBase* theConfig = wxConfigBase::Get();
	theConfig->Write(wxS("TreeView/ActiveComponent"), wxS("none"));
	theConfig->Flush();
}
