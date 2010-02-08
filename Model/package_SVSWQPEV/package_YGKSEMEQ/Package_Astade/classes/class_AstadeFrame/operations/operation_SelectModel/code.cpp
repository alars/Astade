wxConfigBase* theConfig = wxConfigBase::Get();
wxString dir(wxDirSelector("Open Model", theConfig->Read("TreeView/ModelPath"), wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST));

if (!dir.empty())
{
	wxFileName filename(dir);
	LoadModel(filename);
}
