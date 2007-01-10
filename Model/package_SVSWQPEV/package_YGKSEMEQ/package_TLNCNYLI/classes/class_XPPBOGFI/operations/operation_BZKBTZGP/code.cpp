wxConfigBase* theConfig = wxConfigBase::Get();
const wxString& dir = wxDirSelector("Open Model", theConfig->Read("TreeView/ModelPath"), wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

if (!dir.empty())
{
	wxConfigBase* theConfig = wxConfigBase::Get();
	theConfig->Write("TreeView/ActiveComponent", "none");
	theConfig->Flush();
}
