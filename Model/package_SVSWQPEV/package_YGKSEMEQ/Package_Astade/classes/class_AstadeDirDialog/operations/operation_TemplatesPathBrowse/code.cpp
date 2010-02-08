wxConfigBase* theConfig = wxConfigBase::Get();
const wxString& dir = wxDirSelector("Set templates path", theConfig->Read("TreeView/TemplatesPath"), wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
wxFileName filename(dir);

if (!dir.empty())
{
	templatesPathTextControl->SetValue(filename.GetFullPath());
}
