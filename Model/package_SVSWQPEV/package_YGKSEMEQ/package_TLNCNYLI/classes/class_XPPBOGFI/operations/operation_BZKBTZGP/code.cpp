wxConfigBase* theConfig = wxConfigBase::Get();
const wxString& dir = wxDirSelector("Open Model", theConfig->Read("TreeView/ModelPath"));
wxFileName filename(dir);

if (!dir.empty())
{
	wxConfigBase* theConfig = wxConfigBase::Get();
	theConfig->Write("TreeView/ActiveComponent", "none");
	theConfig->Flush();
}
