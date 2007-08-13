wxConfigBase* theConfig = wxConfigBase::Get();
const wxString& dir = wxDirSelector("Open Model", theConfig->Read("TreeView/ModelPath"), wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
wxFileName filename(dir);

if (!dir.empty())
{
	wxConfigBase* theConfig = wxConfigBase::Get();
	theConfig->Write("TreeView/ModelPath", filename.GetFullPath());
	AddToRecentList(filename);
	theConfig->Write("TreeView/ActiveComponent", "none");
	theConfig->Flush();
	delete myTree;
	myTree =  new AstadeTree(this);

	int x,y;
	GetSize(&x, &y);
	SetSize(x-1, y);
	SetSize(x, y);
}
