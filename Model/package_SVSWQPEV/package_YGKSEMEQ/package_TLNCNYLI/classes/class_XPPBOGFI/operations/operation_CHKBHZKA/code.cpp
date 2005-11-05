wxConfigBase* theConfig = wxConfigBase::Get();
const wxString& dir = wxDirSelector("Set templates path",theConfig->Read("TreeView/TemplatesPath"));
wxFileName filename(dir);

if ( !dir.empty() )
{
	templatesPathTextControl->SetValue(filename.GetFullPath());
}
