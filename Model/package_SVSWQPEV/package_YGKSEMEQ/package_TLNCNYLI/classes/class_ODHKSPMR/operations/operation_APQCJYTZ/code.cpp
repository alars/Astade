wxConfigBase* theConfig = wxConfigBase::Get();
const wxString& dir = wxDirSelector("Open Model", theConfig->Read("TreeView/ModelPath"));
wxFileName filename(dir);

if (!dir.empty())
{
	wxConfigBase* theConfig = wxConfigBase::Get();
	theConfig->Write("TreeView/ModelPath", filename.GetFullPath());
	theConfig->Write("TreeView/ActiveComponent", "none");
	theConfig->Flush();
	delete myTree;
	myTree =  new AstadeTree(this);

	int x,y;
	GetSize(&x, &y);
	SetSize(x-1, y);
	SetSize(x, y);
}
