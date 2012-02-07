//~~ void SelectModel(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxString dir(wxDirSelector(wxS("Open Model"), theConfig->Read(wxS("TreeView/ModelPath")), wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST));

if (!dir.empty())
{
	wxFileName filename(dir);
	LoadModel(filename);
}
