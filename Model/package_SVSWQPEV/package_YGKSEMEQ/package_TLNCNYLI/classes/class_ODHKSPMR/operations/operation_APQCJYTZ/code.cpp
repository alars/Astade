wxConfigBase* theConfig = wxConfigBase::Get();
wxString dir(wxDirSelector("Open Model", theConfig->Read("TreeView/ModelPath"), wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST));
wxFileName filename(dir);

if (!dir.empty())
{
	theConfig->Write("TreeView/ModelPath", filename.GetFullPath());
	AddToRecentList(filename);
	theConfig->Write("TreeView/ActiveComponent", "none");
	theConfig->Flush();

	AstadeTree* oldTree = myTree;
	myTree =  new AstadeTree(this);
	AstadeTreeItemBase::SetOurTree(*myTree);
	delete oldTree;

	int x,y;
	GetSize(&x, &y);
	SetSize(x-1, y);
	SetSize(x, y);
}
